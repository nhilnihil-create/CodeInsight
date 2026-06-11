#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    vector<int> cnt(13);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    if (cnt[0] > 0) { cout << 0 << '\n'; return 0; }
    vector<int> base, search;
    base.push_back(0);
    base.push_back(24);
    for(int i = 1; i <= 12; i++) {
        if (cnt[i] >= 3) { cout << 0 << '\n'; return 0; }
        else if (cnt[i] == 1) search.push_back(i);
        else if (cnt[i] == 2) base.push_back(i), base.push_back(24 - i);
    }

    int size = search.size();
    int upper = 1 << size;
    int ans = 0;
    for (int b = 0; b < upper; b++) {
        vector<int> tmp(base.begin(), base.end());
        for (int i = 0; i < size; i++) {
            if ((b >> i) % 2) tmp.push_back(search[i]);
            else tmp.push_back(24 - search[i]);
        }
        int minD = 24;
        for (int i = 0; i < tmp.size()-1; i++) for (int j = i+1; j < tmp.size(); j++)
            minD = min(minD, abs(tmp[i] - tmp[j]));
        ans = max(ans, minD);
    }
    cout << ans << '\n';
}
