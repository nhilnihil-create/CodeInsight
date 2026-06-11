#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}
int f(int x){
    int cnt = 0;
    while(x%2 == 0){
        x /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        ans += f(a[i]);
    }
    cout << ans << endl;
}