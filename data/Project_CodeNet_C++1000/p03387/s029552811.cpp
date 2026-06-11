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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());
    if ( ((abc[0]&1) == (abc[1]&1)) && ((abc[1]&1) == (abc[2]&1)) ) {
        cout << ( abc[2] - abc[1] ) / 2 + ( abc[2] - abc[0] ) / 2 << endl;
    }
    else if ( ((abc[0]&1) == (abc[1]&1)) && ((abc[1]&1) != (abc[2]&1)) ) {
        cout << ( abc[1] - abc[0] ) / 2 + ( abc[2] - abc[1] ) << endl; 
    }
    else if ( ((abc[0]&1) != (abc[1]&1)) && ((abc[1]&1) == (abc[2]&1)) ) {
        cout << ( abc[2] - abc[1] ) / 2 + ( abc[2] - abc[0] + 1 ) / 2 + 1 << endl;
    }
    else if ( ((abc[0]&1) == (abc[2]&1)) && ((abc[1]&1) != (abc[2]&1)) ) {
        cout << ( abc[2] - abc[0] ) / 2 + ( abc[2] - abc[1] + 1 ) / 2 + 1 << endl;
    }

    return 0;
}
