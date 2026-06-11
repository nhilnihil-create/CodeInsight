#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n;i>0;i--)
#define rep1(i,s,n) for(int i=s;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c) 
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<string> svec;

int main(){
    int n,ans=0;
    string a,b,c;
    cin>>n>>a>>b>>c;
    rep(i,n){
        if(a[i]==b[i]&&b[i]==c[i]) continue;
        else if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i]) ans+=2;
        else ans++;
    }
    cout<<ans;
}