#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    string s;
    int k;
    cin >> s >> k;
    int len = int(s.size());
    set<string> ans;
    for(int i=1; i<=k; i++){
        for(int j=0; j<len-i+1; j++){
            string now = s.substr(j,i);
            ans.insert(now);
        }
    }
    auto itr = ans.begin();
    rep(i,k-1) ++itr;
    cout << *itr << endl;
    return 0;
}