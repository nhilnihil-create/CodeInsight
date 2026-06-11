#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
    vector<int> N(4);
    for (int i=0;i<4;i++) cin >> N[i];
    sort(N.begin(),N.end());
    string ans = "NO";
    if (N[0]==1&&N[1]==4&&N[2]==7&&N[3]==9) ans = "YES";
    cout << ans << endl;
}
