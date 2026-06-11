#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w, n; cin >> h >> w >> n;
    ll sr, sc; cin >> sr >> sc;
    string s, t; cin >> s >> t;

    ll lb = 1;
    ll rb = w;
    ll ub = 1;
    ll db = h;

    repr(i, s.size()){
        if(t[i] == 'R'){
            lb = max(1LL, lb - 1);
        }
        else if(t[i] == 'L'){
            rb = min(rb + 1, w);
        }
        else if(t[i] == 'D'){
            ub = max(ub - 1, 1LL);
        }
        else if(t[i] == 'U'){
            db = min(db + 1, h);
        }

        if(s[i] == 'R'){
            // lb = max(1LL, lb - 1);
            rb--;
        }
        else if(s[i] == 'L'){
            // rb = min(rb + 1, w);
            lb++;
        }
        else if(s[i] == 'D'){
            // ub = max(1LL, ub - 1);
            db--;
        }
        else if(s[i] == 'U'){
            // db = min(h, db + 1);
            ub++;
        }

        if(rb < lb || db < ub){
            cout << "NO" << endl;
            return 0;
        }

        // cout << i << " " << lb << " " << rb << " " << ub << " " << db << endl;
    }

    if(ub <= sr && sr <= db && lb <= sc && sc <= rb){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


    return 0;
}