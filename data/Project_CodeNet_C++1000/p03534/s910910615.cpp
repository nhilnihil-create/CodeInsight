#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[3];

int main(){
    cin >> s;
    int sz = s.size();
    REP(i,sz) cnt[(s[i] - 'a')]++;
    int mn = *(min_element(cnt,cnt+3));
    REP(i,3) cnt[i] -= mn;
    cout << (*(max_element(cnt,cnt+3)) <= 1 ? "YES" : "NO") << endl;
}
