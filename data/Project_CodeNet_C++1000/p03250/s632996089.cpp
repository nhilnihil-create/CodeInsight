#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
vector<int> vec(3);
cin >> vec.at(0) >> vec.at(1) >> vec.at(2);
sort(vec.begin(),vec.end());
int ans = vec.at(0) + vec.at(1) + vec.at(2) * 10;
cout << ans << endl;



return 0;
}
