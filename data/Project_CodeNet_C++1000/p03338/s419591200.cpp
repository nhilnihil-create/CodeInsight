#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    repr(i, 1, n){
        int cnt=0;

        for(char c='a'; c<='z'; c++){
            bool left = false, right = false;

            rep(j, i){
                if(s[j] == c) left=true;
            }

            for(int j=i; j<n; j++){
                if(s[j] == c) right=true;
            }

            if(left && right) cnt++;
        }

        if(ans < cnt) ans = cnt;

    }
    cout << ans << endl;

    return 0;
}
