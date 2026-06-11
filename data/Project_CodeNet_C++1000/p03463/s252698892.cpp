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
    int N,A,B;
    cin >> N >> A >> B;
    cout << ((B - A + 1) % 2 == 0 ? "Borys" : "Alice") << endl;
    return 0;
}