#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> x, y, sum;
    int cnt, maxCnt = 0;
    for (int i=1; i<n-1; i++) {
        //0番目からi-1番目までをxに入れ、それ以降をyに入れる
        for (int j=0; j<i; j++) {
            x.insert(s[j]);
        }
        for (int j=i; j<n; j++) {
            y.insert(s[j]);
        }
        cnt = 0;
        for (auto iter=x.begin(); iter!=x.end(); iter++) {
            if (y.find(*iter) != y.end()) {
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
        x.clear();
        y.clear();
    }
    cout << maxCnt << endl;
}