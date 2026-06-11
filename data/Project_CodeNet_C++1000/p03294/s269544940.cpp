#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;


int main () {
    int n;
    cin >> n;
    ll ans =0;
    int a;
    for (int i=0; i < n; i++) {
        cin >> a;
        ans+=(a-1);
    }    
    cout << ans << endl;
    return 0;
}