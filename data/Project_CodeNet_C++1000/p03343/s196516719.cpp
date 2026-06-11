#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int inf = 1 << 30;
int N, K, Q;
int datl[2010][2010], datr[2010][2010];
int A[2010], L[2010], R[2010];
vector<pii> vs;

void update(pii p){
    int val = p.first;
    int idx = p.second;
    for(int i = 0; i < idx; i++){
        R[i] = min(datr[idx][i], R[i]);
    }
    for(int i = idx + 1; i < N; i++){
        L[i] = min(datl[idx][i], L[i]);
    }
}

int solve(){
    int ans = inf;
    for(int i = 0; i < N; i++){
        int val = vs[i].first;
        int idx = vs[i].second;
        if(L[idx] + R[idx] + 1 >= K){
            int cnt = 1;
            for(int j = i + 1; j < N; j++){
                idx = vs[j].second;
                if(L[idx] + R[idx] + 1 >= K) cnt++;
                if(cnt == Q){
                    ans = min(ans, vs[j].first - val);
                    break;
                }
            }
        }
        update(vs[i]);
    }
    if(Q == 1) ans = 0;
    return ans;
}

void init(){
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        vs.push_back({A[i], i});
    }
    sort(vs.begin(), vs.end());
    for(int i = 0; i < N; i++){
        for(int j = i - 1; j >= 0; j--){
            if(A[j] > A[i]) datl[j][i]++;
            if(j > 0) datl[j - 1][i] = datl[j][i];
        }
        L[i] = datl[0][i];
        for(int j = i + 1; j < N; j++){
            if(A[j] >= A[i]) datr[j][i]++;
            datr[j + 1][i] = datr[j][i];
        }
        R[i] = datr[N][i];

    }
}

int main(){
    init();
    cout << solve() << endl;
    return 0;
}