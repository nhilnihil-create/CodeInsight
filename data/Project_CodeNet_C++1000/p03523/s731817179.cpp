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
string s,tar = "AKIHABARA";
bool Solve() {
    cin >> s;
    if(s.length() > 9) {
	return false;
    }
    for(int i = 0 ; i < 9 ; ++i) {
	if(s.length() <= i) s += "A";
	if(s[i] != tar[i]) {
	    if(tar[i] == 'A') {
		s.insert(i,1,'A');
	    }
	    else return false;
	}
    }
    if(s != tar) return false;
    return true;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    if(Solve()) puts("YES");
    else puts("NO");
    return 0;
}
