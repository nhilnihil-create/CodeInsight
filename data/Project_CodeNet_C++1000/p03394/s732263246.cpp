#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    if(n == 3) {
        cout << 2 << " " << 3 << " " << 25 << endl;
        return 0;
    }

    const int A = 30000;

    if(n == 20000) {
        for(int i = 2; i <= A; i++) {
            if(i%2 == 0 || i%3 == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
        return 0;
    }

    if(n%2 == 1) {
        cout << A/2 << " ";
        n--;
    }

    int cnt = 0;
    for(int i = 2; i < A/2; i++) {

        if(i%2 == 0 || i%3 == 0) {
            cout << i << " " << A - i << " ";
            cnt += 2;
        }

        if(cnt == n) {
            break;
        }
    }

    cout << endl;
    return 0;
}