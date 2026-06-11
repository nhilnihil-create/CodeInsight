#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int A1,A2,A3;
    cin >> A1 >> A2 >> A3;
    int ans = max({A1,A2,A3}) - min({A1,A2,A3});
    cout << ans << endl;
}