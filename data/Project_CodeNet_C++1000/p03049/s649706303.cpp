#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 0, c1 = 0, c2 = 0, c3 = 0;
    rep(i, n){
        string s;
        cin >> s;

        int len = s.size();
        rep(j, len-1){
            if(s[j] == 'A' && s[j+1] == 'B'){
                ans++;
            }
        }

        if(s[0] == 'B'){
            if(s[len-1] == 'A'){
                c1++;
            }else{
                c2++;
            }
        }else{
            if(s[len-1] == 'A'){
                c3++;
            }
        }
    }

    ans += c1 + min(c2, c3);
    if(c2 == 0 && c3 == 0 && c1 != 0) ans--;

    cout << ans << "\n";


    return 0;
}
