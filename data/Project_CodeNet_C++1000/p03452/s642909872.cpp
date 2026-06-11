#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

vector < pp > V[N];
int T[N],H[N],n,m,i,x,y,z;

void f(int x){
    H[x] = 1;
    for(int y, i=0; i<V[x].size(); i++){
        if(!H[ y = V[x][i].st ]){
            T[y] = T[x] + V[x][i].nd;
            f(y);
        }
        else if(T[y] != T[x] + V[x][i].nd){
            puts("No"); exit(0);
        }
    }
}

signed main(){
    scanf("%d%d",&n,&m);
    for(; m-- ;){
        scanf("%d%d%d",&x,&y,&z);
        V[x].pb(mp(y,z));
        V[y].pb(mp(x,-z));
    }

    for(i=1;i<=n;i++){
        if(H[i]) continue;
        f(i);
    }

    puts("Yes");
    return 0;
}