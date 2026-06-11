#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 2000009
#define MOD 1000000007
//#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    //cout<<s<<endl;
   
    ll ans = 0;
    ll ans1=0;

    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i]=='0'){
            ans++;
        }else{
            ans1++;
        }
    }
    cout << min(ans,ans1)*2 << endl;
    return 0;
}