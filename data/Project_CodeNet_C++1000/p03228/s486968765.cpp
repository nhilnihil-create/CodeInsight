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
    int a, b, k;
    cin >> a >> b >> k;

    int taka = a, aoki = b;
    int turn = 0;
    while(1) {
        if(turn%2 == 0) {
            if(taka%2 == 1) {
                taka--;
            }
            aoki += taka/2;
            taka /= 2;
        }
        else {
            if(aoki%2 == 1) {
                aoki--;
            }
            taka += aoki/2;
            aoki /= 2;
        }
        turn++;
        if(turn == k) {
            break;
        }
    }

    cout << taka << " " << aoki << endl;
    return 0;
}