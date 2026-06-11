#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int R;
    cin >> R;
    string ans;
    if(R < 1200) ans = "ABC";
    else if(R >= 1200 && R < 2800) ans = "ARC";
    else ans = "AGC";
    cout << ans << endl;
}