#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define RREPALL(i,v) for (int i = v.size()-1; i >= 0; i--)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

vector<char> t, d;

int main()
{
    int n, q;
    string s;
    cin>>n>>q;
    cin>>s;

    REP(i,q) {
        char tt, td;
        cin>>tt>>td;
        t.push_back(tt);
        d.push_back(td);
    }

    int l = 0, r = n, mid, lp, rp;
    while(l != r - 1) {
        mid = (l + r) / 2;
        lp = mid;
        REP(i,q) {
            if (t[i] == s[lp]) {
                if (d[i] == 'L') {
                    lp--;
                } else {
                    lp++;
                }
            }
            if (lp == -1 || lp == n) {
                break;
            }
        }
        if (lp == -1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    lp = l;
    l = 0, r = n;
    while(l != r - 1) {
        mid = (l + r) / 2;
        rp = mid;
        REP(i,q) {
            if (t[i] == s[rp]) {
                if (d[i] == 'L') {
                    rp--;
                } else {
                    rp++;
                }
            }
            if (rp == -1 || rp == n) {
                break;
            }
        }
        if (rp == n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    rp = r;
    cout<<rp - lp - 1<<endl;

    return 0;
}
