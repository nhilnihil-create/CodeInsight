#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main(){
    string s,t;
    cin >> s >> t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());

    int k = max(s.size(),t.size());

    string ans = "No";
    rep(i,k) {
        if (i>s.size()-1) {
            ans = "Yes";
            break;
        }
        else if (i>t.size()-1) {
            break;
        }
        else if (s[i]<t[i]) {
            ans = "Yes";
            break;
        }
        else if (s[i]>t[i]) {
            break;
        }
    }
    cout << ans << endl;
}
