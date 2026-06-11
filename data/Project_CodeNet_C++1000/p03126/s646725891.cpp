#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n,m,k,inp;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,n){
        cin >> k;
        rep(j,k){
            cin >> inp;
            a[inp-1]++;
        }
    }
    int cnt = 0;
    rep(i,m){
        if (a[i] >= n)cnt++;
    }
    cout << cnt;
}