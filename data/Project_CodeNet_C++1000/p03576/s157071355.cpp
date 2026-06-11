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
    int N,K;
    cin >> N >> K;
    vl x(N),y(N);
    ve<pair<ll,ll>> A(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        x[i] = a,y[i] = b;
        A[i] = {a,b};
    }
    sor(A);
    //rep(i,N) cout << A[i].fi  << " " << A[i].se << endl;
    ll ans = 9000000000000000000;
    rep(i,N){
        vl B = {};
        ll sq_x = 0,sq_y = 0;
        reps(j,i,i+K-1) B.push_back(A[j].se);
        reps(j,i+K-1,N){
            sq_x = A[j].fi - A[i].fi;
            B.push_back(A[j].se);
            sort(all(B));
            //rep(p,N) cout << B[p]<< " ";
            //cout << endl;
            rep(k,int(B.size())){
                if(k+K-1 >= int(B.size())) break;
                sq_y = B[k+K-1]-B[k];
                //cout << sq_x << " " << sq_y << endl;
                ans = min(sq_x*sq_y,ans);
            }
        }
    }
    out(ans);
    
    



    return 0;
}
