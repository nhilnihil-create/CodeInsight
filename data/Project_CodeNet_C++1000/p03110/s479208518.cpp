#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int n;
    cin>>n;
    
    double ans = 0, x;
    string s;
    
    rep(i,n){
        cin>>x>>s;
        if(s=="BTC") x *= 380000;
        ans += x;
    }
    printf("%.10lf\n", ans);
    return 0;
}