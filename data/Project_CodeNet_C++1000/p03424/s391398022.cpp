
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n; cin >> n;
    vector<char> s(n);
    string ans="Three";
    rep(i,n){
        cin >> s[i];
        if(s[i] == 'Y'){
            ans = "Four";
            break;
        }
    }
    cout << ans << endl;

}