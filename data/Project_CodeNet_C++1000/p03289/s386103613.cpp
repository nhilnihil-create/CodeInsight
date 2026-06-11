#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    string s;
    cin >> s;
    set<char> ls;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char c: alphabet) {
        ls.insert(c);
    }
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    } else {
        string ssub = s.substr(2, s.size() - 3);
        int cc = 0;
        set<char> other;
        for (char c: ssub) {
            if (c == 'C') {
                cc++;
            } else {
                other.insert(c);
            }
        }
        other.insert(s[1]);
        other.insert(s[s.size()-1]);
        if (cc != 1) {
            cout << "WA" << endl;
            return 0;
        }
        for (char c: other) {
            if (ls.find(c) == ls.end()) {
                cout << "WA" << endl;
                return 0;
            }
        }
        cout << "AC" << endl;
    }
    return 0;
}