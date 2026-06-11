#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    int N;
    cin >> N;
    string s[N];

    int na,nb, nab;
    na = nb = nab = 0;
    int ans  = 0;
    rep(i,N) {
        cin >> s[i];
        if (s[i][0] == 'B' && s[i].back()=='A') {
            nab++;
        }
        else if (s[i][0] == 'B') {
            nb++;
        }
        else if (s[i].back()=='A') {
            na++;
        }
        rep(j,s[i].size()-1) {
            if (s[i][j]=='A' && s[i][j+1]=='B') {
                ans++;
            }
        }
    }

    if (na+nb==0) {
        ans += max(nab-1,0);
    }
    else {
        ans += nab+min(na,nb);
    }
    cout << ans << endl;


}
