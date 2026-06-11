#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int n;cin>>n;
    vi a(n);
    double sum = 0;
    
    rep(i,n){
        cin>>a[i];
        sum += a[i];
    }
    
    sum /= n;
    
    double dif = 100;
    int ans;
    
    rep(i,n){
        if(dif>abs(sum-a[i])){
            ans = i;
            dif = abs(sum-a[i]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}