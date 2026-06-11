#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> V;
    if (s[0] == '0') V.push_back(0); // dummy
    char lastCh = s[0];
    int cnt = 1;
    if (s.size() == 1) V.push_back(1);
    for(int i=1; i<s.size(); i++) {
        char ch = s[i];
        if(ch != lastCh) {
            V.push_back(cnt);
            cnt = 0;
        }
        lastCh = ch;
        cnt++;
        if (i==s.size()-1) V.push_back(cnt);
    }
    if (s[s.size()-1] == '0') V.push_back(0); // dummy

    // 累積和
    ll S[V.size()+1];
    S[0] = 0;
    for(int i=1; i<=V.size(); i++) {
        S[i] = S[i-1] + V[i-1];
    }

    int w = 2*k+1;
    if (w > V.size()) {
        cout << S[V.size()] << endl;
        return 0;
    }

    ll ans = 0;
    for (int i=1; i+w-1<=V.size(); i+=2) {
        ans = max(ans, S[i+w-1]-S[i-1]);
    }

    cout << ans << endl;

    
    return 0;
}
