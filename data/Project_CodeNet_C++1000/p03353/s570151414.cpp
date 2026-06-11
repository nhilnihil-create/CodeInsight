#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    string s; int k;
    cin >> s >> k;
    int n = (int) s.length();
    
    set<string> substrs;
    
    for(int l = 1; l <= k; l++){
        for(int i = 0; i + l <= n; i++){
            substrs.insert(s.substr(i,l));
        }
    }
    
    string ans;
    for(string str: substrs){
        ans = str;
        k--;
        if(k==0) break;
    }
    
    cout << ans << endl;
}