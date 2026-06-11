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
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



int main()
{
    int N,Z,W;
    cin >> N >> Z >> W;
    vi a(N);
    in(N,a);
    
    if(N==1) {
        out(abs(a[0]-W));
        return 0;
    }
    
    int ans = 0;
    ans = max(abs(W-a.back()),abs(a[N-1]-a[N-2]));
    
    
    
    out(ans);

    return 0;
}
