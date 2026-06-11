#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    vector<double> a(3);
    rep(i,3) cin >> a.at(i);
    sort(a.begin(),a.end());
    cout << a.at(0)*a.at(1)/2 << endl;
}