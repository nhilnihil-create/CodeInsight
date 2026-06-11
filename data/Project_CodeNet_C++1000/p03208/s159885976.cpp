#include <bits/stdc++.h>
#include <limits.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int m=INT_MAX;
    rep(i,n-k+1){
        m = min(m,h[i+k-1]-h[i]);
    }

    cout << m <<endl;
}