#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
//const ll MOD = 1000000007;
const ld PI = (acos(-1));
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
double rad(double a) {return a * 180 / PI;}

//dpTable
int dp[100050];

vector<ll> rsk(100050);

int main(){
    string S;
    cin >> S;
    int ans = 0,a = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
            a++;
        }
        else {
            ans = max(a,ans);
            a = 0;
        }
    }
    if (ans < a) ans = a;
    cout << ans << endl;
    return 0;
}