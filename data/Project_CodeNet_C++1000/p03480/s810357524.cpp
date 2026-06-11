#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl
#define pno cout << "no" << endl
#define pYe cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pYE cout << "YES" << endl
#define pNO cout << "NO" << endl
#define prin(num) cout << num << endl
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX_V 100005
#define MAX_E 100005
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef priority_queue<P> PQ;

int main(void) {
    string s;
    cin >> s;
    ll i;
    ll min=(ll)s.size();
    for(i=0; i<s.size()-1; i++) {
        if(s[i]!=s[i+1]) {
            min=min(min, max(i+1, (ll)s.size()-i-1));
        }
    }
    
    if(min==0 && s[0]=='1') {
        prin(s.size());
    }else {
        prin(min);
    }
}
