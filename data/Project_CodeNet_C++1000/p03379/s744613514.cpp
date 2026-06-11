#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long


int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n); //xをソートしたもの
    vector<int> ans(n);
    rep(i,n){
        int c;
        cin >> c;
        x[i] = c;
        y[i] = c;
    }
    sort(y.begin(),y.end());

    rep(i,n){
      if(x[i] < y[n/2]) ans[i] = y[n/2];
      else ans[i] = y[n/2-1];
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}