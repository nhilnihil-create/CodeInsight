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
    ve<int> P(N);
    in(N,P);
    rep(i,N) P[i]--;
    
    ve<int> A(N);
    rep(i,N) A[P[i]] = i;
    
    int a = -1;
    int b = 0;
    int an = 0;
    rep(i,N){
        if(a < A[i]) b++;
        else an = max(an,b),b = 1;
        
        if(i == N-1) an = max(an,b);
        else a = A[i];
    }
 
    out(N-an);


    return 0;
}
