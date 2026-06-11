#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
vector<int> vec(3);
for (int i = 0;i < 3;i++) cin >> vec.at(i);
sort(vec.begin(),vec.end());
int ans = vec.at(1) - vec.at(0) + (vec.at(2) - vec.at(1));
cout << ans << endl;



return 0;
}
