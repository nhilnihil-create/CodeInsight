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
int H,W,N;
vector<int> v[MAXN];
bool pass[MAXN];
void Solve() {
    read(H);read(W);read(N);
    int x,y;
    for(int i = 1 ; i <= N ; ++i) {
	read(x);read(y);
	v[y].pb(x);
    }
    for(int i = 1 ; i <= W ; ++i) v[i].pb(H + 1);
    sort(v[1].begin(),v[1].end());
    int ans = v[1][0] - 1;
    int t = 0;
    for(int i = 2 ; i <= W ; ++i) {
	sort(v[i].begin(),v[i].end());
	int s = v[i].size();
	int m = 0;
	for(int k = 0 ; k < s ; ++k) {
	    if(v[i][k] <= i + t) {pass[v[i][k]] = 1;m = max(v[i][k],m);}
	    else if(pass[v[i][k] - 1]) {pass[v[i][k]] = 1;m = max(v[i][k],m);}
	    else {
		ans = min(ans,v[i][k] - 1);
		break;
	    }
	}
	t = max(t,m - i + 1);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
