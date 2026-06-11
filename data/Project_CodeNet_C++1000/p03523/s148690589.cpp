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
#define mkp(a, b) make_pair(a, b)
#define pb(t) push_back(t)
#define ft first
#define sc second
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;




int main(void) {
    string s;
    cin >> s;
    string a[]={
        "AKIHABARA",
        
        "AKIHABAR",
        "AKIHABRA",
        "AKIHBARA",
        "KIHABARA",
        
        "AKIHABR",
        "AKIHBAR",
        "AKIHBRA",
        "KIHABAR",
        "KIHABRA",
        "KIHBARA",
        
        "AKIHBR",
        "KIHABR",
        "KIHBAR",
        "KIHBRA",
        
        "KIHBR"
    };
    
    for(ll i=0; i<16; i++) {
        if(s==a[i]) {
            pt("YES");
            return 0;
        }
    }
    pt("NO");
    
}


