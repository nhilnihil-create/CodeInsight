#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i))
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(x,v) for(const auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//lambda: [&](int x, int y){return x<y;}

signed main(void){
    int n;cin>>n;
    int ans=0;

    int both=0,a=0,b=0;
    rep(i,n){
        string s;cin>>s;
        rep(j,s.size()-1)if(s[j]=='A'&&s[j+1]=='B')ans++;
        if(s[0]=='B'&&s.back()=='A')both++;
        else if(s[0]=='B')b++;
        else if(s.back()=='A')a++;
    }
    if(a+b==0)ans+=max(0LL,both-1);
    else ans+=both+min(a,b);
    cout << ans << endl;

}
