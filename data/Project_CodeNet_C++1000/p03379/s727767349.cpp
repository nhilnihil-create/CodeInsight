#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<int> y = x;
    sort(y.begin(), y.end());
    if(y[n/2-1] == y[n/2]){
        rep(i,n) cout << y[n/2] << endl;
    }
    else{
        rep(i,n){
            if(x[i] <= y[n/2-1]) cout << y[n/2] << endl;
            else cout << y[n/2-1] << endl;
        }
    }
}