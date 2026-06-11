#include <cstdio>
#include <string>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <tuple>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i=a;i<n;++i)
#define repeq(i, a, n) for(int i=a;i<=n;++i)
#define repi(m, itr) for (auto itr = m.begin();itr != m.end();++itr)
#define per(i, a, n) for (int i=n-1; i>=a;--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

// D - Wide Flip
string S;
const int INF = 10000000;
int ans = INF;

int main(){
    cin >> S;

    int len = S.length();

    rep(i, 0, len-1){
        if(S[i] != S[i+1]){
            ans = min(ans, max(i+1, len - (i+1)));
        }
    }

    if(ans == INF){
        ans = len;
    }
    cout << ans << endl;
    return 0;
}


