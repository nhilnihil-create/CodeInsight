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
int n,m,cnt=0,o,p,aa[220000],cntl=0,ab[220000];
pair<int,int> pp[220000];
string s,ss[220000];
char c,cc[220000];
queue<int> que;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>aa[i];
    }
    rep(i,n-1){
        if(aa[i]==aa[i+1]){
            aa[i+1]=INF;
            cnt++;
        }
    }
    cout<<cnt;
}