#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, a;
    cin >> n >> a;
    if ( n % 500 <= a ) {
        cout << "Yes\n";
    } 
    else {
        cout << "No\n";
    }
    return 0;
}
