#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll A,B,C;
    cin >> A >> B >> C;
    ll K;
    cin >> K;
    ll ans ;
    if( K % 2 == 0){
        ans = (A - B);
    }
    else{
        ans = (B - A);
    }
    cout << ans << endl;
}