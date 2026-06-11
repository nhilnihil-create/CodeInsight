#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = 0, r = s.size()-1;

    int ans = 0;
    while(l < r){
        if(r == l) break;
        if(s[l] == s[r]){
            l++;
            r--;
        }else if(s[l] == 'x'){
            l++;
            ans++;
        }else if(s[r] == 'x'){
            r--;
            ans++;
        }else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
