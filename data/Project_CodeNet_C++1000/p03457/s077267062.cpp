#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    vi t(n),x(n),y(n);
    rep(i,n){
        cin>>t[i]>>x[i]>>y[i];
    }
    
    int dx,dt;
    
    rep(i,n){
        
        if(!i){
            dx = abs(x[i]) + abs(y[i]);
            dt = t[i];
        }else{
            dx = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
            dt = t[i]-t[i-1];
        }
        
        if((dx+dt)%2){
            cout << "No" << endl;
            return 0;
        }
        if(dx>dt){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}