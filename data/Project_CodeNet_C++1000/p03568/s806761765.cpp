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
int n,m,cnt=1,aa[220000],ans=0;
pair<int,int> pp[220000];
string s,sa[220000],sb[220000];
char c;
queue<int> que;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>aa[i];
        if(aa[i]%2==0){
            cnt*=2;
        }
    }
    cout<<pow(3,n)-cnt<<endl;
}