#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int a,b,k,aa[110000],cnt=0;
pair<string,int> p[220000];
string s,ss[220000],x;
char c;
signed main(){
    cin>>a>>b>>k;
    while(1){
        if(a%2==1){
            a--;
        }
        b+=a/2;
        a/=2;
        cnt++;
        if(cnt==k){
            break;
        }
        if(b%2==1){
            b--;
        }
        a+=b/2;
        b/=2;
        cnt++;
        if(cnt==k){
            break;
        }
    }
    cout<<a<<' '<<b;
}