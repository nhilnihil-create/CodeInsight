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
    int N;
    cin >> N;
    vector<int> t(N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int T = 0; 
    for (int i = 0; i < N; i++) {
        T += t[i];
    }
    vector<int> mae(2*T+1), ushiro(2*T+1), speed(2*T+1), M(2*T+1);
    int z = 1;
    M[0] = 0;
    for (int i = 0; i < N; i++) {
        z--;
        M[z] = min(M[z], 2*v[i]);
        z++;
        for (int j = 1; j < 2*t[i]+1; j++) {
            M[z] = 2*v[i];
            z++;
        }
    }

    mae[0] = 0;
    for (int i = 1; i < 2*T+1; i++) {
        mae[i] = min(M[i], mae[i-1] + 1);
    }
    ushiro[2*T] = 0;
    for (int i = 2*T-1; i >= 0; i--) {
        ushiro[i] = min(M[i], ushiro[i+1] + 1);
    }

    for (int i = 0; i < 2*T+1; i++) {
        speed[i] = min(mae[i], ushiro[i]);
    }

    double ans = 0;
    ans = speed[0] + speed[2*T];
    for (int i = 1; i < 2*T; i++) {
        ans += 2 * speed[i];
    }
    ans = ans / 8.0;


    printf("%32.18f\n", ans);
}