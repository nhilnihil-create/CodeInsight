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
    int n;
    cin >> n;
    map<int, int> mp_odd;
    map<int, int> mp_even;
    rep(i, n) {
        int a;
        cin >> a;
        if ( i&1 ) {
            ++mp_odd[a];
        }
        else {
            ++mp_even[a];
        }
    }
    int max_odd_num = 0;
    int max_odd = 0;
    int second_max_odd_num = 0;
    int second_max_odd = 0;

    int max_even_num = 0;
    int max_even = 0;
    int second_max_even_num = 0;
    int second_max_even = 0;

    for ( auto m : mp_odd ) {
        if ( m.second > max_odd ) {
            second_max_odd_num = max_odd_num;
            second_max_odd = max_odd;
            max_odd = m.second;
            max_odd_num = m.first;
        }
        else if ( m.second > second_max_odd ) {
            second_max_odd = m.second;
            second_max_odd_num = m.first;
        }
    }

    for ( auto m : mp_even ) {
        if ( m.second > max_even ) {
            second_max_even_num = max_even_num;
            second_max_even = max_even;
            max_even = m.second;
            max_even_num = m.first;
        }
        else if ( m.second > second_max_even ) {
            second_max_even = m.second;
            second_max_even_num = m.first;
        }
    }

    if ( max_odd_num != max_even_num ) {
        cout << n - max_odd - max_even << endl;
    }
    else {
        cout << min(n - max_odd - second_max_even, n - second_max_odd - max_even) << endl;
    }

    return 0;
}
