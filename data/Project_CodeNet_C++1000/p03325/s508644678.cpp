#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int solve (int x){
    int k=0;
    while(x%2 != 1){
        k++;
        x /= 2;
    }
    return k;
}


int main(){
    int n;
    int cnt=0;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        cnt += solve(a[i]);
    }
    cout << cnt << endl;
    
}