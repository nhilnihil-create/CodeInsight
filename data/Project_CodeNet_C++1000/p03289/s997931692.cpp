#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string s;
    cin >> s;
    if(s[0] != 'A'){cout << "WA" <<endl;return 0;}
    int cnt =0;
    rep(i, 1, s.size()){
        if(2 <= i && i <= s.size()-2) {
            if(s[i] == 'C') cnt++;
            if(cnt >1){cout << "WA" <<endl;return 0;}
        } else {
            if (65 <= s[i] && s[i] <= 90 ) {
                cout << "WA" <<endl;return 0;
            }
        }
    }
    if(!cnt){cout << "WA" <<endl;return 0;}
    cout << "AC" <<endl;return 0;
    return 0;
}

