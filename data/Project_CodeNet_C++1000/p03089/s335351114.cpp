#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> b;
    vector<int> ope;
    rep(i, N) {
        int num; cin >> num;
        num--;
        b.push_back(num);
    }
    while(b.size()) {
        int i = 0;
        rep(j, b.size()) {
            if(b[j] == j) i = j;
        }
        if(b[i] != i) {
            cout << -1 << endl;
            return 0;
        }
        ope.push_back(i);
        b.erase(b.begin() + i);
    }
    reverse(ope.begin(), ope.end());
    for(auto& e: ope) cout << e + 1 << endl;



    return 0;
}
