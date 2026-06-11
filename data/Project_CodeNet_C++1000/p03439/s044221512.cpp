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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    int l = -1;
    int r = 2 * n;
    int middle;
    int male_mod = -1;
    rep(i, 20) {
        middle = ( l + r ) / 2;
        cout << middle % n << endl;
        string s;
        cin >> s;
        if ( s == "Vacant" ) break;
        if ( i == 0 ) {
            if ( s == "Male" ) male_mod = 0;
            else               male_mod = 1;
            l = middle;
        }
        else {
            if ( middle % 2 == male_mod && s == "Female" || 
                 middle % 2 != male_mod && s == "Male"   ) {
                r = middle;
            }
            else {
                l = middle;
            }
        }
    } 
    return 0;
}
