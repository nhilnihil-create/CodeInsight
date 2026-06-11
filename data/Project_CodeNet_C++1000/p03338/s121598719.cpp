#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N; cin >> N;
    string S; cin >> S;
    set<char> hoji, judge;
    int ans = 0, cnt;
    for(int i = 0; i < N - 1; i++) {
        cnt = 0;
        if(!hoji.count(S.at(i))) {
            hoji.insert(S.at(i));
        }
        for(int j = i + 1; j < N; j++) {
            if(hoji.count(S.at(j))) {
                if(!judge.count(S.at(j))) {
                judge.insert(S.at(j));
                }
            }
        }
        cnt = judge.size();
        for (auto k: judge) {
            judge.erase(k);
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}