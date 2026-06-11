#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,a;
    double t;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    double maxim = 1e9;
    int point = 0;
    rep(i,n){
        if(abs(a-(t-h[i]*0.006)) < maxim){
            maxim = abs(a-(t-h[i]*0.006));
            point = i+1;
        }
    }
    cout << point << endl;
}