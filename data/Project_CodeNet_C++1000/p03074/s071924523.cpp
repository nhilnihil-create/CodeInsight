#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vin zero,one;
    int res=0;char tmp=s[0];
    rep(i,n){
        if(s[i]!=tmp){
            if(tmp=='0')zero.push_back(res);
            else one.push_back(res);
            tmp=s[i];
            res=0;
        }
        res++;
    }
    if(s[n-1]=='0')zero.push_back(res);
    else one.push_back(res);
    if(zero.size()<=k){
        cout<<n<<endl;
        return 0;
    }
    int zs=zero.size();
    int os=one.size();
    vin upright(zs+1),handstand(os+1);
    upright[0]=0;handstand[0]=0;
    if(zs==os&&s[0]=='0'){
        reverse(all(s));
        reverse(all(zero));
        reverse(all(one));
    }
    rep(i,zs)upright[i+1]=upright[i]+zero[i];
    rep(i,os)handstand[i+1]=handstand[i]+one[i];
    int ans=0;
    if(zs==os){
        rep(i,os-k)ans=max(ans,upright[i+k]-upright[i]+handstand[i+k+1]-handstand[i]);
        ans=max(ans,upright[zs]-upright[zs-k]+handstand[os]-handstand[os-k]);
    }
    else{
        if(s[0]=='0'){
            ans=upright[k]+handstand[k];
            rep(i,os-k)ans=max(ans,upright[i+k+1]-upright[i+1]+handstand[i+k+1]-handstand[i]);
            ans=max(ans,upright[zs]-upright[zs-k]+handstand[os]-handstand[os-k]);
        }
        else rep(i,os-k)ans=max(ans,upright[i+k]-upright[i]+handstand[i+k+1]-handstand[i]);
    }
    cout<<ans<<endl;
}