#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(p.begin(), p.end());
    p[n-1] /= 2;
    int sum = 0;
    rep(i,n) sum += p[i];
    cout << sum << endl;
}