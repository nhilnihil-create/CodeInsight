#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n; cin >> n;
    vector<ll> l(n+1);
    l[0] = 2;
    l[1] = 1;
    for (int i = 2; i <= n; i++) {
        l[i] = l[i-1] + l[i-2];
    } 
    cout << l[n] << endl;

    return 0;
}