#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>x,b(n);
    rep(i,n)cin>>b[i];
    rep(i,n){
        if(b[i]-1>i){cout<<-1<<endl; return 0;}
        x.insert(x.begin()+b[i]-1,b[i]);
    }
    rep(i,n){
        cout<<x[i]<<endl;
    }
}