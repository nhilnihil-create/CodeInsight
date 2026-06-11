#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000007
#define endl "\n" 
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    int n, a, b; cin >> n;
    if(n == 1) {
        cout << "Hello World" << endl;
    } else {
        cin >> a >> b;
        cout << a+b << endl;
    }

    return 0;
}
