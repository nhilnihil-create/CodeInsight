#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;

    int s1=0, s0 = 0;

    rep(i, s.size()) {
        if(s[i] == '1') s1++;
        else s0++; 
    }

    cout << min(s1, s0) * 2 << endl;

    return 0;
}