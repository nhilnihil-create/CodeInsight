#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N; cin >> N;
int A = 0, B = 0, C = 0;
int cnt = 0;
rep(i,N) {
    string s;
    cin >> s;
    rep(i,SZ(s)-2) {
        if(s.substr(i,2) == "AB") cnt++;
    }
    if(s[0] == 'B' && s[SZ(s)-1] == 'A') {
        C++;
        continue;
    }
    if(s[0] == 'B') B++;
    if(s[SZ(s)-1] == 'A') A++;
}
if(A + B == 0 && C > 0) cout << cnt + C - 1 << endl;
else cout << cnt + min(A, B) + C << endl;
return 0;
}