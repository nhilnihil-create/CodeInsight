#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<ll>> W(8, vector<ll> (N));
    for (int i = 0; i < 8; i++) {
        if(i & 1){
            for (int j = 0; j < N; j++) {
                W[i][j] = x[j];
            }
        }
        else{
            for (int j = 0; j < N; j++) {
                W[i][j] = -x[j];
            }
        }

        if(i & 2){
            for (int j = 0; j < N; j++) {
                W[i][j] += y[j];
            }
        }
        else{
            for (int j = 0; j < N; j++) {
                W[i][j] -= y[j];
            }
        }

        if(i & 4){
            for (int j = 0; j < N; j++) {
                W[i][j] += z[j];
            }
        }
        else{
            for (int j = 0; j < N; j++) {
                W[i][j] -= z[j];
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        sort(ALL(W[i]), greater<ll> ());
    }

    ll tmp;
    ll ans = 0;
    for (int i = 0; i < 8; i++) {
        tmp = 0;
        for (int j = 0; j < M; j++) {
            tmp += W[i][j];
        }
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);

}