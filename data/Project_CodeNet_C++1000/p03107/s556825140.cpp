#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int zero = 0, one = 0;
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i]=='0') zero++;
        else one++;
    }
    cout << zero+one-abs(zero-one) << endl;
    return 0;
}