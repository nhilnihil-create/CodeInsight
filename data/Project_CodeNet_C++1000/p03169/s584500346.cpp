#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n; 
vector<vector<vector<ld>>> dp(305,vector<vector<ld>>(305,vector<ld>(305,-1.0)));

ld rec(int one,int two,int three){

    if(one == 0 && two == 0 && three == 0) return 0.0;
    if(dp.at(one).at(two).at(three) >= 0) return dp.at(one).at(two).at(three);

    ld res = 0.0;
    if(one > 0) res += rec(one-1,two,three)*one;
    if(two > 0) res += rec(one+1,two-1,three)*two;
    if(three > 0) res += rec(one,two+1,three-1)*three;
    res += n;
    res /= (one + two + three);

    return dp.at(one).at(two).at(three) = res;
}

int main(){

    cin >> n;
    vector<int> ti(3,0);
    rep(i,n){
        int now; cin >> now;
        now--;
        ti.at(now)++;
    }

    cst(14) << rec(ti.at(0),ti.at(1),ti.at(2)) << endl;

    return 0;   

}
