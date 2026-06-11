#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    string s;
    int ans = 1000;
    int tmp = 0;
    cin >> s;
    for(int i = 0; i < s.length()-2; i ++){
        tmp = 0;
        tmp += ((int)(s[i]-'0'))*100;
        tmp += ((int)(s[i+1]-'0'))*10;
        tmp += ((int)(s[i+2]-'0'));
        ans = min(ans,abs(tmp-753));
    }

    cout << ans;


    return 0;
}