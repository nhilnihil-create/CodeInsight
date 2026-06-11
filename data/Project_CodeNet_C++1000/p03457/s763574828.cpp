#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<pair<int,pair<int, int>>> T(N);
    for(int i = 0; i < N; i++) cin >> T[i].first >> T[i].second.first >> T[i].second.second;
    sort(T.begin(), T.end());
    int tim = 0;
    int prex = 0, prey = 0;
    string ans = "Yes";
    for(int i = 0; i < N; i++) {
        int nowx = T[i].second.first, nowy = T[i].second.second;
        int dist = abs(nowx - prex) + abs(nowy - prey);
        if((T[i].first - tim - dist) % 2 == 0 && T[i].first - tim - dist >= 0) {
            tim += dist;
            if(tim > T[i].first) {
                ans = "No";
                break;
            }
            prex = nowx, prey = nowy;
        }
        else {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}