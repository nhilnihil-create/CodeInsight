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
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;
//https://pyteyon.hatenablog.com/entry/2019/03/11/200000#Union-Find-%E6%9C%A8%E3%81%AE%E5%AE%9F%E8%A3%85
// union by size + path having
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        // どちらも同じ
        return true;
    }
}


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    ll k;
    ll g,e;
    ll q;
    cin>>n>>m;
    vector<P> p(m);
    vector<P> ps(m);
    rep(i,m){
        cin>>a>>b;
        p[i]=P(a,b);
        ps[i]=P(a,b);

    }
    sort(all(p),comp);
    map<P,ll> mp;

    ll si=p[0].first;
    ll ctr=1;
    rep(i,m){
        if(si!=p[i].first){
            ctr=1;
            si=p[i].first;
        }
        mp[p[i]]=ctr;
            ctr++;
    }
    rep(i,m){
            cout<<setfill('0')<<right<<setw(6)<<ps[i].first;
            cout<<setfill('0')<<right<<setw(6)<<mp[ps[i]]<<endl;
    }
    return 0;
}
