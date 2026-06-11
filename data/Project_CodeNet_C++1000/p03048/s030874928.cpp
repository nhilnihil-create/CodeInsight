#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

ll MOD = 998244353;


int main() {
    int r,g,b,n; cin >> r >> g >> b >> n;
    int cnt = 0;
    for(int i = 0; i <= n / r;i++){
        for(int j = 0; j <= n / g; j++){
            if((n - i * r -j * g) >=0&&(n - i * r -j * g) % b == 0) cnt++;
        }
    }
    cout << cnt << endl;
}
