#include <bits/stdc++.h>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main(void){
    int n;
    string s;
    cin>>n>>s;
    int res=INF;
    vector<int> l(n+1),r(n+1);
    rep(i,1,n+1){
        if(s[i-1]=='#')l[i]=l[i-1]+1;
        else l[i]=l[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(s[i+1]=='.')r[i]=r[i+1]+1;
        else r[i]=r[i+1];
    }
    rep(i,0,n){
        res=min(res,l[i]+r[i]);
    }
    cout<<res<<endl;
    return 0;
}