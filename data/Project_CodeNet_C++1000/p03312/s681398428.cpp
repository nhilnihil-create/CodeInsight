#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
ll A[200010];
ll sums[200010];

ll solve1(){
    ll ans = 1LL << 60;
    // [0, i) [i, N) に分ける
    for(int i = 2; i < N - 1; i++){
        vector<int> bef, aft;
        {
            int lb = -1;
            int ub = i;
            while(ub - lb > 1){
                int mid = (ub + lb) / 2;
                ll a = sums[mid + 1];
                ll b = sums[i] - sums[mid];
                if(a >= b) ub = mid;
                else lb = mid;
            }
            if(ub > 0) bef.push_back(ub - 1);
            bef.push_back(ub);
        }
        {
            int lb = i - 1;
            int ub = N;
            while(ub - lb > 1){
                int mid = (ub + lb) / 2;
                ll a = sums[mid + 1] - sums[i];
                ll b = sums[N] - sums[mid];
                if(a >= b) ub = mid;
                else lb = mid;
            }
            if(ub > i) aft.push_back(ub - 1);
            aft.push_back(ub);
        }
        for(int b : bef){
            for(int a : aft){
                int f1 = 0;
                int t1 = b;
                int f2 = b + 1;
                int t2 = i - 1;
                int f3 = i;
                int t3 = a;
                int f4 = a + 1;
                int t4 = N - 1;
                ll v1 = sums[t1 + 1] - sums[f1];
                ll v2 = sums[t2 + 1] - sums[f2];
                ll v3 = sums[t3 + 1] - sums[f3];
                ll v4 = sums[t4 + 1] - sums[f4];
                ll vs[] = {v1, v2, v3, v4};
                sort(vs, vs + 4);
                ans = min(ans, vs[3] - vs[0]);
            }
        }
    }
    return ans;
}

ll solve2(){
    ll ans = 1LL << 60;
    // [0, i) [i, N) に分ける
    int lpos = 0;
    int rpos = 2;
    for(int i = 2; i < N - 1; i++){
        rpos = max(i, rpos);
        ll v1 = -1;
        ll v2 = -1;
        ll v3 = -1;
        ll v4 = -1;
        // 一番左と次の総和が、一番近くなるところを求める
        while(1){
            ll a1 = sums[lpos + 1];
            ll b1 = sums[i] - sums[lpos + 1];
            v1 = a1; v2 = b1;
            if(lpos >= i - 2) break;
            ll a2 = sums[lpos + 2];
            ll b2 = sums[i] - sums[lpos + 2];
            if(abs(a1 - b1) >= abs(a2 - b2)){
                lpos++;
            }
            else break;
        }
        while(1){
            ll a1 = sums[rpos + 1] - sums[i];
            ll b1 = sums[N] - sums[rpos + 1];
            v3 = a1; v4 = b1;
            if(rpos >= N - 2) break;
            ll a2 = sums[rpos + 2] - sums[i];
            ll b2 = sums[N] - sums[rpos + 2];
            if(abs(a1 - b1) >= abs(a2 - b2)){
                rpos++;
            }
            else break;
        }
        ll vs[] = {v1, v2, v3, v4};
        sort(vs, vs + 4);
        ans = min(ans, abs(vs[0] - vs[3]));
    }
    return ans;
}

int main(){

    while(cin >> N){
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < N; i++) sums[i + 1] = sums[i] + A[i];
        cout << solve2() << endl;
    }
 
    return 0;
}
