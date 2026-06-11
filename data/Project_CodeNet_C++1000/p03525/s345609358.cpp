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
    int N;cin >> N;
    ve<int> D(N);
    in(N,D);
    
    sor(D);
    
    int a=0,b=0;
    
    int ans = 100;
    
    rep(i,N){
        ans = min(ans,D[i]);
        int aa = abs(a-D[i]);
        int bb = abs(b-(24-D[i]));
        
        if(aa > bb){
            a = D[i];
            ans = min(aa,ans);
            ans = min(ans,abs(b-a));
        }else{
            b = 24-D[i];
            ans = min(bb,ans);
            ans = min(ans,abs(b-a));
        }
    }

    
    out(ans);
    


    return 0;
}
