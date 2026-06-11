#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{

    ve<ve<int>> g(4, vi(4,0));
    rep(i,3){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    vector<int> c(4);
    rep(i,4) c[i] = i;
    
    
    do{
        int aa = 1;
        rep(i,3) if(g[c[i]][c[i+1]] == 1) aa++;
        
        if(aa == 4){
            cout << "YES" << endl;
            return 0;
        }
        
        //outve(c);
    } while (next_permutation(all(c)));
    
    
    cout << "NO" << endl;
    
    
    

    return 0;
}
