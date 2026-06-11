#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
struct node{
    int u, v, w;
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};
vector<node>ans;
inline int lowbit(int x) {
    return x & -x;
}
int main() {
    int L;
    scanf("%d", &L);
    for(int i=19;i>1;i--) {
        ans.push_back(node(i, i+1, 0));
        ans.push_back(node(i, i+1, (1<<(20-i-1))));
    }
    while( L ) {
        int p = int(log2(lowbit(L)));
        if( p == 19 ) {
            ans.push_back(node(1, 2, 0));
            ans.push_back(node(1, 2, 1<<18));
        }
        else ans.push_back(node(1, 20-p, L^lowbit(L)));
        L ^= lowbit(L);
    }
    printf("%d %d\n", 20, ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w);
} 
