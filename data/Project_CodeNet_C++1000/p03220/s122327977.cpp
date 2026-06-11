#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=INF,aa[220000],ans=0,t,a;
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<int> que;
signed main(){
    cin>>n>>t>>a;
    rep(i,n){
        cin>>aa[i];
        if(abs(a*1000-t*1000+6*aa[i])<cnt){
            cnt=abs(a*1000-t*1000+6*aa[i]);
            ans=i+1;
        }
    }
    cout<<ans<<endl;
}