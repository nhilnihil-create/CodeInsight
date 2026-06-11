#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n){
        ans += a[i]-1;
    }
    cout << ans;
}