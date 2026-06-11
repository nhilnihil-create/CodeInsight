#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vpint = vector<pint>;

#define repi(i,start,end) for(int (i)=(start),TemPNuM=(int)(end);(i)<TemPNuM;++(i))
#define rep(i,end) repi((i),0,(end))
#define rfor(x,v) for(auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fsort(v,lambda) sort(all((v)),(lambda))
#define vin(v) rep(i,(v).size())cin >> (v)[i];
#define vpin(v) rep(i,(v).size())cin>>v[i].first>>v[i].second
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void println(T a){if(cout.precision()!=12)cout<<setprecision(12);cout<<a<<endl;}
//lambda: [](int x, int y){return x<y;}

const int MOD = 1e9+7;

signed main(void){
    int n;cin>>n;
    string s;cin>>s;
    vint cnt(26,1);
    rep(i,26){
        rfor(c,s){
            if(c=='a'+i)cnt[i]++;
        }
    }
    ll ans=1;
    rfor(x,cnt){
        ans = ans*x%MOD;
    }

    cout << ans-1 << endl;
    return 0;
}
