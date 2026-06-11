#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    char chr[4] = {'A','T','G','C'};
    int ans = 0, cnt = 0;
    rep(i, n){
        bool flag = false;
        rep(j, 4){
            if(s[i] == chr[j]) flag = true;
        }
        if (flag){
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    cout << ans << endl;  
}