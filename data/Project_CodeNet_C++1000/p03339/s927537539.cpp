#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    string s;
    cin >> N >> s;

    ll count = 0;
    for(int i=0; i<N; i++) {
        if(s[i] == 'E') count++;
    }
    ll min_count = count;
    for(int i=0; i<N; i++) {
        if(s[i] == 'W') {
            count++;
        }
        else {
            count--;
        }
        min_count = min(min_count, count);
    }
    cout << min_count << endl;
}