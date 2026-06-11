#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
vector<int> vec(3);
int ans = 0;
for (int i = 0;i < 3;i++) {
    cin >> vec.at(i);
    }
int K;
cin >> K;
sort(vec.begin(),vec.end());
for (int i =0;i < K;i++) vec.at(2) *= 2;
   
ans += vec.at(0) + vec.at(1) + vec.at(2);

cout << ans << endl;

return 0;
}

