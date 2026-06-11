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



int main()
{
    int N;
    cin >> N;
    ve<ll> A(N);
    in(N,A);
    if(A[0] != 0) {
        out(-1);
        return 0;
    }
    ll ans = 0;
    reps(i,1,N){
        if(A[i] > A[i-1]+1){
            out(-1);
            return 0;
        }
        
        if(A[i] == 0) continue;
        
        if(A[i] == A[i-1]+1) ans++;
        else ans += A[i];
        
        
    }

    out(ans);


    return 0;
}
