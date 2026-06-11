//Dubious Document 2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s,t;cin>>s>>t;
    int c = -1;
    if(s.size()<t.size()){
        cout<<"UNRESTORABLE"<<nnn;
        return 0;
    }
    rep(i,0,s.size()-t.size()+1){
        bool flag = true;
        rep(j,i,t.size()+i){
            if(s[j]=='?')continue;
            if(s[j]!=t[j-i]){
                flag=false;
            }
        }
        if(flag)c=i;
    }
    rep(i,0,s.size()){
        if(s[i]!='?')break;
        if(i==s.size()-1){
            rep(i,0,s.size()-t.size()){
                cout<<"a";
            }
            cout<<t<<nnn;
            return 0;
        }
    }
    if(c==-1){
        cout<<"UNRESTORABLE"<<nnn;
    }else{
        rep(i,c,t.size()+c){
            s[i]=t[i-c];
        }
        rep(i,0,s.size()){
            if(s[i]=='?'){
                s[i]='a';
            }
        }
        cout<<s<<nnn;
    }
    return 0;
}