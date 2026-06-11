#include <bits/stdc++.h>
#include<limits.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n,t,a;
    cin>>n;
    cin >> t>>a;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int dest = -1;
    double diff = -1.0;
    rep(i,n){
        double temp = h[i]*0.006;
        temp = t-temp;
        if(abs(temp-a)<diff || diff==-1.0){
            diff = abs(temp-a);
            dest = i;
        }
    }

    cout << dest+1 <<endl;
}