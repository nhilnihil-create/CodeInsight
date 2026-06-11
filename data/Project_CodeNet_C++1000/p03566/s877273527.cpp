#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
int t[105];
int v[105];
double dp[20010][101];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> t[i];
        t[i] += t[i-1];
    }
    for(int i = 1; i <= N; i++) cin >> v[i];
    t[N+1] = 20001;
    v[N+1] = 0;
    for(int i = 1; i <= 100; i++) dp[0][i] = -1e9;
    int index = 1;
    //for(int i = 1; i <= N + 1; i++) cerr << t[i] << endl;
    for(int timer = 0; timer <= 20000; timer++) {
        while(t[index] <= timer) index++;
        //cerr << timer << " " << index << endl;
        for(int j = 0; j <= 100; j++) dp[timer+1][j] = -1e9;
        for(int velocity = 0; velocity <= v[index]; velocity++) {
            //cerr << timer << " " << index << " " << velocity << " " << dp[timer][velocity] << endl;
            for(int NewV = velocity - 1; NewV <= velocity + 1; NewV++){
                if(NewV > v[index]) continue;
                if(NewV < 0) continue;
                double nowval = (velocity + NewV);
                nowval /= 2;
                if(velocity == NewV && velocity < v[index]) nowval += 0.25;
                chmax(dp[timer+1][NewV], dp[timer][velocity] + nowval);
            }
        }
    }
    cout << fixed << setprecision(20) << dp[20001][0] << endl;
    return 0;
}
