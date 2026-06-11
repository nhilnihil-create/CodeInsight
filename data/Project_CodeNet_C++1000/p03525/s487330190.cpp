#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (int i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (int i = x.size()-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define fst first
#define scd second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

int n;
set<int> st;

int main()
{
    cin>>n;
    st.insert(0);
    REP(i,n) {
        int d;
        cin>>d;
        if (d == 0) {
            cout<<0<<endl;
            return 0;
        }
        else if (!st.count(d)) {
            st.insert(d);
        } else if (!st.count(24 - d)) {
            st.insert(24 - d);
        } else {
            cout<<0<<endl;
            return 0;
        }
    }

    RREP(t,12+1) {
        //cout<<"t = "<<t<<" : ";
        set<int> c(st);
        c.insert(24);
        auto itr = c.begin();
        auto nitr = next(itr);
        bool flag = true;
        while (nitr != c.end()) {
            //cout<<*itr<<"-"<<*nitr<<"  ";
            if (*nitr - *itr >= t) {
                itr++;
                nitr++;
            } else if (*nitr < 12 && !st.count(24 - *nitr)) {
                c.insert(24 - *nitr);
                c.erase(nitr);
                nitr = next(itr);
            } else {
                flag = false;
                break;
            }
        }
        //nextline;

        if (flag) {
            cout<<t<<endl;
            return 0;
        }
    }

    return 0;
}
