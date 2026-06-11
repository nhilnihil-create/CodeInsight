#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    int n;cin>>n;
    for (int i = 0; i < s.length(); i=i+n)
    {
        /* code */
         cout<<s[i];
    }

}
int main()
{    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // int  t; cin >> t; while (t--) solve();
    solve();
    return 0;
}
