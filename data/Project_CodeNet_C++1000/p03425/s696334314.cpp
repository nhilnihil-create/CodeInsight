#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }

    vector<ll> counter(5,0);

    rep(i,N){
        char lead_char = S[i][0];
        switch(lead_char){
            case 'M':
                counter[0]++;
                break;
            case 'A':
                counter[1]++;
                break;
            case 'R':
                counter[2]++;
                break;
            case 'C':
                counter[3]++;
                break;
            case 'H':
                counter[4]++;
                break;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 5; i++){
        for (int j = i+1; j < 5; j++){
            for (int k = j+1; k < 5; k++){
                ans += counter[i]*counter[j]*counter[k];
            }
        }
    }
    cout << ans << endl;
}