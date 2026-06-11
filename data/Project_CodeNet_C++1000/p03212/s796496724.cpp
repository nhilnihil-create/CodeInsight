#include <iostream>
#include <iomanip>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)


int n;
char target[] = {'7', '5', '3'};

bool count(int num) {
    int cnt = 0;
    for (char c : target) {
        int nn = num;
        while (nn > 0) {
            if (nn % 10 == c - '0') {
                cnt++;
                break;
            }
            nn /= 10;
        }
    }
    if (cnt >= 3) {
        return true;
    } else {
        return false;
    }
}

int dfs(ll num) {
    if (num > n)return 0;
    int ret = count(num) ? 1 :0;
    for(char c : target){
        ret += dfs(num * 10 + (c-'0'));
    }
    return ret;
}


int main() {
    cin >> n;
    cout << dfs(0) << endl;
    return 0;
}
