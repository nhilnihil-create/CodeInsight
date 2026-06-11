
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int a,b,c;cin>>a>>b>>c;
    int d=10*a+b+c;
    int e=10*b+c+a;
    int f=10*c+a+b;
    cout<<max({d,e,f})<<endl;

    
}