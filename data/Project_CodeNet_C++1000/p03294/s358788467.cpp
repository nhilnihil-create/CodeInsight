#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int f(int m,vector<int> a){
    int ans = 0;
    rep(i,a.size()){
        ans += m%a[i];
    }
    return ans;
}

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    rep(i,n){
        cin >> a[i];
        ans += a[i]-1;
    }
    cout << ans<<endl;
}