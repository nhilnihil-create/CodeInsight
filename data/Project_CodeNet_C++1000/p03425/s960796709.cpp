// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// g++ hoge.cpp -std=c++17 -I . でコンパイルできる
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
//#include <atcoder/all>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
//using namespace atcoder;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    cin>>n;
    string str[n];
    rep(i,n)cin>>str[i];
    vector<ll> v(5);
    ll r,h;
    rep(i,n){
        if(str[i][0]=='M') v[0]++;
        if(str[i][0]=='A') v[1]++;
        if(str[i][0]=='R') v[2]++;
        if(str[i][0]=='C') v[3]++;
        if(str[i][0]=='H') v[4]++;
    }
    rep(i,5)rep(j,i)rep(k,j){
        sum+=v[i]*v[j]*v[k];
    }
    cout<<sum<<endl;
    return 0;
}
