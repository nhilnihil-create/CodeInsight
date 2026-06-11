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
int n,m,cnt=0,aa[220000],ans=0,t,a;
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<int> que;
signed main(){
    cin>>n;
    rep(i,50){
        rep(j,9){
            if(pow(i+1,j+2)<=n){
                cnt=max(double(cnt),pow(i+1,j+2));
            }
        }
    }
    cout<<cnt<<endl;
}