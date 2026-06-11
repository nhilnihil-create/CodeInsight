#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> V(N);
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }
    ll ans = 0;
    ll tmp;
    ll cnt;
    vector<ll> t;
    for (ll a = 0; a <= N; a++) {
        for (ll b = 0; b <= N; b++) {
            if(a + b > K) continue;
            if(a + b > N) continue;
            t.clear();
            for (ll i = 0; i < a; i++) {
                t.push_back(V[i]);
            }
            for (ll i = N-1; i >= N-b; i--) {
                t.push_back(V[i]);
            }
            sort(ALL(t));
            cnt = K - a - b;
            tmp = 0;
            for (ll i = 0; i < a+b; i++) {
                if(t[i] < 0){
                    if(cnt > 0){
                        cnt--;
                    }
                    else{
                        tmp += t[i];
                    }
                }
                else{
                    tmp += t[i];
                }
            }

            // printf("%lld %lld %lld ", a, b, tmp);
            // for (int i = 0; i < a+b; i++) {
            //     printf("%lld ", t[i]);
            // }
            // cout << endl;
            ans = max(tmp, ans);


        }
    }

    printf("%lld\n", ans);

}