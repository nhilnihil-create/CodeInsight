#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


int N;
ve<ve<char>> A;
bool check(int x, int y){
    
    ve<ve<char>> SS(N,ve<char>(N,'a'));
    rep(i,N) rep(j,N){
        SS[i][j] = A[i+x][j+y];
    }
    
    rep(i,N) reps(j,i,N){
        if(SS[i][j] != SS[j][i]){
            return false;
        }
    }
    return true;
}


int main()
{
    cin >> N;
    ve<ve<char>> S(N,ve<char>(N,'a'));
    rep(j,N) in(N,S[j]);
    A.resize(2*N,ve<char>(2*N,'a'));
    rep(i,N) rep(j,N){
        A[i][j] = S[i][j];
        A[i+N][j] = S[i][j];
        A[i][j+N] = S[i][j];
        A[i+N][j+N] = S[i][j];
    }
    int ans = 0;
    rep(i,N) if(check(0,i)) ans+=(N-i);
    reps(i,1,N) if(check(i,0)) ans+=(N-i);
    
    out(ans);

    return 0;
}
