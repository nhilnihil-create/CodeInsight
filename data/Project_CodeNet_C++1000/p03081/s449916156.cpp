#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m , n) for(int i = (n);i >=(m);--i)
#define PB push_back
#define MP make_pair
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x,y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1000000007;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////


/*（๑•﹏•๑｀) */
int N,Q;
string s,ss;

vector<char> T;
vector<char> D;

bool chkleft(int pos){
    REP(i,Q){
        if (pos == -1) return true;
        char t = T[i];
        char d = D[i];

        if (s[pos] != t) continue;
        if (d == 'L') pos--;
        else pos++;
    }

    if (pos == -1) return true;
    else return false;
}

bool chkright(int pos){
    REP(i,Q){
        if (pos == -1) return true;
        char t = T[i];
        char d = D[i];

        if (s[pos] != t) continue;
        if (d == 'R') pos--;
        else pos++;
    }

    if (pos == -1) return true;
    else return false;
}

int lbinary_search(){
    // lower_bound (a-1,b] (ans = [a,b])
    // <= left never satisfy
    // right <= always satisfy

    int left = -1;
    int right = N+1; // index of size + 1;

    while(right - left > 1){
        int mid = left + (right - left) / 2;

        if (!chkleft(mid)) right = mid;
        else left = mid;
    }

    // left is the maximum that don't satisfy the condition.
    // right is the minimum that satisfies the condtion.

    return right;

}


int rbinary_search(){
    // lower_bound (a-1,b] (ans = [a,b])
    // <= left never satisfy
    // right <= always satisfy

    int left = -1;
    int right = N+1; // index of size + 1;

    while(right - left > 1){
        int mid = left + (right - left) / 2;

        if (!chkright(mid)) right = mid;
        else left = mid;
    }

    // left is the maximum that don't satisfy the condition.
    // right is the minimum that satisfies the condtion.

    return right;

}

int main() {
    cin >> N >> Q;
    cin >> ss;
    s = ss;
    s.PB('-');

    REP(i,Q){
        char t,d;
        cin >> t >> d;
        T.PB(t);
        D.PB(d);
    }

    int L = lbinary_search();

    reverse(ALL(ss));
    s = ss;
    s.PB('-');



    int R = rbinary_search();

    cout << N - L - R << endl;
}
