#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,a,b,ans=0;
    cin>>n>>a>>b;
    for(lli i=1;i<=n;i++){
        lli num=0;
        lli o,t,s,f,l;
        o=t=s=f=l=0;
        o=i%10;
        t=(i%100-o)/10;
        if(t<0) t=0;
        s=(i%1000-10*t-o)/100;
        if(s<0) s=0;
        f=(i%10000-100*s-10*t-o)/1000;
        if(f<0) f=0;
        l=i/10000;
        num=o+t+s+f+l;
        if(num>=a&&num<=b) ans+=i;
    }
    out(ans);
}