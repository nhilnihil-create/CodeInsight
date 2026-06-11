#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
int main( ) {
    //freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[256];
    map<char,ll> m;
    ll cnt=0;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",&s);
        m[s[0]]++;
    }
    if(sz(m)<3){
        printf("%d",0);
        return 0;
    }
    // m['M']*m['A']*m['R']*m['C']*m['H']
    cnt = m['M']*m['A']*m['R']+m['M']*m['A']*m['C']+m['M']*m['A']*m['H']+m['A']*m['R']*m['C']+m['A']*m['R']*m['H']+m['R']*m['C']*m['H']+m['M']*m['R']*m['C']+m['M']*m['R']*m['H']+m['M']*m['C']*m['H']+m['A']*m['C']*m['H'];
    printf("%lld",cnt);
    return 0;
}