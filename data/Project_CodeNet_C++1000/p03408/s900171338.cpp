#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,M,ans = 0;
    string s;
    map<string,int> mp;
    cin >> N;

    rep(i, N){
        cin >> s;
        mp[s]++;
    }

    cin >> M;

    rep(i,M){
        cin >> s;
        mp[s]--;
    }

    for(auto x:mp){
        ans = max(ans,x.second);
    }

    cout << ans << endl;
    
    return 0;
}