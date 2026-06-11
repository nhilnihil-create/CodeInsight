#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[505][505];

//dpTable
//bool dp[100050];

int main(){
    int N;
    cin >> N;
    vector<tuple<string,int,int>> S;
    rep (i,N) {
        string a;
        int b;
        cin >> a >> b;
        S.push_back(make_tuple(a,(-1 * b),i + 1));
    }
    sort(S.begin(),S.end());
    for (tuple<string,int,int> t : S) {
        string x;
        int y,z;
        tie(x,y,z) = t;
        cout << z << endl;
    }
    return 0;
}