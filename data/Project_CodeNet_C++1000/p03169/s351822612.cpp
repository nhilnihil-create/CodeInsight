#include <bits/stdc++.h>
#include <tuple>
using namespace std;

#ifdef LOCAL 
string to_string(char a) { return string(1,a); }
string to_string(bool a) { return a ? "1" : "0"; }
string to_string(const char* a) { return (string)a; }
string to_string(string a) { return a; }
string to_string(vector<bool> v) {
	string s = "["; for(unsigned i=0;i<v.size();i++){ s += ((i>0)?" ":"");
    s += char('0'+v[i]); } 	s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) {
	bool b = 1; string s = "["; for (const auto& x: v) {
		if (!b) {s += ", ";} b = 0; s += to_string(x); } s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void dbgf() { cerr << endl; }
template<class H, class... T> void dbgf(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	dbgf(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << " = ", dbgf(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
#define boolout(x) cout<<(x?"YES":"NO")<<endl;
typedef long long ll;


double p[301][301][301];
double ev[301][301][301];
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(4);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1;

    for (int c = n; c >= 0; --c) {
        for (int b = n; b >= 0; --b) {
            for (int a = n; a >= 0; --a) {
                dbg(a, b, c, p[a][b][c]);
                if (a+b+c>n) {
                    continue;
                }
                if (a==0 && b==0 && c==0) {
                    continue;
                }
                double prob;
                //we pick 0
                prob = (a+b+c)/(double)n;
                ev[a][b][c] += 1/prob * p[a][b][c];
                //p[a][b][c] += p[a][b][c] * prob;
                //we pick 1
                if (a>0) {
                    prob = (double)a/(a+b+c);
                    p[a-1][b][c] += p[a][b][c] * prob;
                    ev[a-1][b][c] += ev[a][b][c] * prob;
                }
                //we pick 2
                if (b>0) {
                    prob = (double)b/(a+b+c);
                    p[a+1][b-1][c] += p[a][b][c] * prob;
                    ev[a+1][b-1][c] += ev[a][b][c] * prob;
                }
                //
                //we pick 3
                if (c>0) {
                    prob = (double)c/(a+b+c);
                    p[a][b+1][c-1] += p[a][b][c] * prob;
                    ev[a][b+1][c-1] += ev[a][b][c] * prob;
                }
            }
        }
    }
    cout << setprecision(10) << ev[0][0][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}

