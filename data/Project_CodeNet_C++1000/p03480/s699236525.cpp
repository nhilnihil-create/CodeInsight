#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<iomanip>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long

int main(){
    string s; cin >> s; int n = s.size(); int ans = 1e7;
    rep(i, n-1){
        if(s[i] != s[i+1]) ans = min(ans, max(i+1, n-i-1));
    }
    if(ans == 1e7) ans = n;
    cout << ans << endl;
}