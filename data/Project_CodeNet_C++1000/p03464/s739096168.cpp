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
    
    int K;
    cin >> K;
    
    ve<ll> A(K);
    in(K,A);
    rev(A);
    ll minA = 2,maxA = 2;
    
    rep(i,K){
        //cout << A[i] << " " << minA << " " << maxA << endl;
        ll a = maxA/A[i],mm = maxA;
        if(a*A[i] >= minA && a*A[i] <= maxA) maxA = a*A[i]+A[i]-1;
        else {out(-1);return 0;}

        if(minA%A[i] == 0) continue;
        else{
            ll b = minA/A[i];
            if((b+1)*A[i] >= minA && (b+1)*A[i] <= mm) minA = (b+1)*A[i];
            else {out(-1);return 0;}
        }
        
        //cout << A[i] << " " << minA << " " << maxA << endl;
    }

    cout << minA << " " << maxA << endl;

  
    
    return 0;
}
