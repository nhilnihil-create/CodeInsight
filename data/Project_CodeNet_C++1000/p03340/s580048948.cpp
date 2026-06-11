#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;



int main()
{
    int N;
    cin >> N;
    vl A(N);
    rep(i,N) cin >> A[i];
    
    ll ans = 0;
    ll B = 0;
    ll t = 0;
    ll oldt = -1;
    for (ll s = 0; s < (ll)N; s++) {
        while (B+A[t] == (A[t]^B) && t < (ll)N) {
            B += A[t];
            t++;
        }
        ll n = t-s;
        ans += n;
        if(t==s){
            t++;
        }else{
            B-=A[s];
        }
    }
    

    out(ans);


    return 0;
}
