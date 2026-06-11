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
int n,m,cnt=0,aa[220000],ans=0,ab[220];
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<int> que;
signed main(){
    cin>>n>>m>>cnt;
    rep(i,n){
        if((i+1)/10000+(i+1)/1000%10+(i+1)/100%10+(i+1)/10%10+(i+1)%10>=m&&(i+1)/10000+(i+1)/1000%10+(i+1)/100%10+(i+1)/10%10+(i+1)%10<=cnt){
            ans+=i+1;
        }
    }
    cout<<ans<<endl;
}