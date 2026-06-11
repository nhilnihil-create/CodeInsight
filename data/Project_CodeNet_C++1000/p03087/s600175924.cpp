#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> memo(n);
    vector<int> ans(n);
    memo[0] = 0;
    for(int i=1; i<n; i++){
        if(s[i] == 'C' && s[i-1] == 'A'){
            memo[i] = memo[i-1] +1;
        }
        else memo[i] = memo[i-1];
    }
    rep(i,q){
        int a,b;
        cin >> a >> b;
        a--; b--;
        ans[i] = memo[b] - memo[a] ;
    }
    rep(i,q){
        cout << ans[i] << endl;
    }
}