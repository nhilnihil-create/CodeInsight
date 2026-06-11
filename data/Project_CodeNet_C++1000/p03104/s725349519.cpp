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
    ll a,b;cin>>a>>b;
    if(a==b){
        cout<<a<<endl;
        return 0;
    }
    if(b==a+1){
        cout<<(a^b)<<endl;
        return 0;
    }
    ll ans;
    //(2n)^(2n+1)=1
    if(a%2&&b%2){
        if((b-a)/2%2)ans=a^(ll)1;
        else ans=a^(ll)0;
    }
    else if(a%2==0&&b%2){
        if((b-a+1)/2%2)ans=1;
        else ans=0;
    }
    else if(a%2&&b%2==0){
        if((b-a-1)/2%2)ans=a^(ll)1;
        else ans=a^(ll)0;
        ans^=b;
    }
    else{
        if((b-a)/2%2)ans=b^(ll)1;
        else ans=b^(ll)0;
    }
    cout<<ans<<endl;
}