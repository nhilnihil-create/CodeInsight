#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int N = 1e5 + 5;

map < int , int > H;
vector < int > V[N];
pp A[N];
int sz[N];

int f(int x, int d){
    int t = d;
    for(int i=0; i<V[x].size(); i++)
        t += f(V[x][i], d+1);
    return t;
}

signed main(){
    int n;
	cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        scanf("%lld",&x);
        A[i] = mp(x,i);
        H[x] = i;
    }
            
    sort(A+1 , A+n+1);
    for(int i=n; i>=2; i--){
        int x = A[i].nd;
        sz[x]++;
        H[ A[i].st ] = 0; 
        int par = H[ A[i].st - n + 2 * sz[x] ];
        if(par == 0){
            cout << -1;
            return 0;
        }
        
        sz[par] += sz[x];
        V[par].pb(x);
    }
    
    if(f(A[1].nd, 0) != A[1].st){
        cout << -1;
        return 0;
    }
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<V[i].size(); j++)
            printf("%lld %lld\n", i, V[i][j]);
    
    return 0;
}