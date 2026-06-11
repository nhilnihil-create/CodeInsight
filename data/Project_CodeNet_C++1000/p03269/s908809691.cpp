#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define db double
 
const int MAXN = (1 << 17 | 3);
const int MAXE = 400400;
const int INF = 0x3f3f3f3f;
 
template<typename T> inline void CheckMax(T &A, T B) {
	A < B ? A = B : A;
}
 
template<typename T> inline void CheckMin(T &A, T B) {
	A > B ? A = B : A;
}
 
template <typename T> inline void read(T &x) {
    int c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
}

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<Edge>ans;

#define lowbit(x) (x & -x)

signed main() {
    int L;
    scanf("%d",&L);
    for(int i = 19; i > 1; i--) {
        ans.push_back(Edge(i, i+1, 0));
        ans.push_back(Edge(i, i+1, (1 << (20 - i - 1))));
    }
    while(L) {
        int p = int(log2(lowbit(L)));
        if(p == 19) {
            ans.push_back(Edge(1, 2, 0));
            ans.push_back(Edge(1, 2, 1 << 18));
        }
		else ans.push_back(Edge(1, 20 - p, L ^ lowbit(L)));
        L ^= lowbit(L);
    }
    printf("%d %d\n", 20, (int) ans.size());
    for(int i = 0; i < (int) ans.size(); i++)
        printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w);
    return 0;
}