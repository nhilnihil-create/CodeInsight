#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    cout << a.at(a.size()-1) - a.at(0) << endl;
}
