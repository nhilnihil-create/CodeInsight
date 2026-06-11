#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    int N;
    cin >> N;
    V(string) S(N);
    cout << 0 << endl;
    string t;
    cin >> t;
    S[0] = t;
    if(t=="Vacant") return 0;
    int l=0, r=N;
    rep(i, 19) {
        int mid = (l+r)/2;
        cout << mid << endl;
        string s;
        cin >> s;
        if(s=="Vacant") return 0;
        S[mid] = s;
        if(abs(mid-l)%2 && S[l]==s) r = mid;
        else if(abs(mid-l)%2==0 && S[l]!=s) r = mid;
        else if(abs(mid-r)%2 && S[r%N]==s) l = mid;
        else if(abs(mid-r)%2==0 && S[r%N]!=s) l = mid;
    }

    return 0;
}