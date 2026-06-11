#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n;
    cin>>n;
    vector<int> X(n),Y(n);
    rep(i,n)cin>>X[i];
    rep(i,n)Y[i]=X[i];
    sort(Y.begin(),Y.end());
    int t2=Y[n/2],t1=Y[n/2-1];
    rep(i,n){
       if(X[i]<=t1)cout<<t2<<endl;
       else cout<<t1<<endl;
    }
}