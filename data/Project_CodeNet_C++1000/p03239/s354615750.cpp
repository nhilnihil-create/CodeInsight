#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,tt;
    cin>>n>>tt;
    vv c(n, vi (2));
    rep(i,n){
        cin>>c[i][0]>>c[i][1];
    }
    
    sort(c.begin(), c.end());
    
    rep(i,n){
        if(c[i][1]<=tt){
            cout<<c[i][0]<<endl;
            return 0;
        }
    }
    
    cout<<"TLE"<<endl;
    return 0;
}