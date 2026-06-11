#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    string s, ans = "";
    cin >> s;
    int w;
    cin >> w;
    for (int i = 0; i < s.size(); i += w){
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}