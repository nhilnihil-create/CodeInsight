#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int N;
cin >> N;
vector<pair<double,string>> vec(N);
for (int i = 0;i < N;i++) {
    cin >> vec.at(i).first >> vec.at(i).second;
}
double ans = 0;
for (int i = 0;i < N;i++) {
if (vec.at(i).second == "BTC") {
    ans += vec.at(i).first * 380000.0;
} else ans += vec.at(i).first;
}

cout << ans << endl;


return 0;
}
