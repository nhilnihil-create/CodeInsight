#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 200005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
    if(c == '-') f = -1;
    c = getchar();
    }
    while(c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
    out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
int A[MAXN];
int pw[MAXN][25],cnt[MAXN],ans;
vector<pii > v;
void Init() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(A[i]);
    cnt[1] = 1000000000;
    for(int i = 1 ; i <= N ; ++i) {
        pw[i][0] = 1;
        for(int j = 1 ; j <= 20 ; ++j) {
            if(pw[i][j - 1]  > N / i) {
                cnt[i] = j - 1;break;
            }
            pw[i][j] = pw[i][j - 1] * i;
        }
    }
}
bool check(int mid) {
    v.clear();
    v.pb(mp(A[1],0));int sum = A[1];
    for(int i = 2 ; i <= N ; ++i) {
	if(A[i] <= A[i - 1]) {
	    if(mid == 1) return false;
	    if(sum < A[i - 1]) {v.pb(mp(A[i - 1] - sum,0));sum = A[i - 1];}
	    int s = v.size() - 1;
	    for(int k = s ; k >= 0 ; --k) {
		if(sum - v[k].fi >= A[i]) {sum -= v[k].fi;v.pop_back();}
		else {
		    int t = sum - A[i];
		    if(t > cnt[mid]) v[k].se = 0;
		    else v[k].se /= pw[mid][t];
		    v[k].fi -= t;
		    sum = A[i];
		}
		if(sum == A[i]) break;
	    }
	    s = v.size() - 1;
	    for(int k = s ; k >= 0 ; --k) {
		if(v[k].fi <= cnt[mid]) {
		    if(v[k].se + 1 < pw[mid][v[k].fi]) {++v[k].se;break;}
		    else {
			v[k].se = 0;if(k == 0) return false;
		    }
		}
		else {++v[k].se;break;}
	    }
	}
    }
    return true;
}
void Solve() {
    int l = 1,r = N;
    while(l < r) {
	int mid = (l + r) >> 1;
	if(check(mid)) r = mid;
	else l = mid + 1;
    }
    out(l);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Init();
    Solve();
}
