/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back   
#define sz(a) ((int)a.size())
#define all(a) a.begin() , a.end()
using namespace std;
typedef long long ll ; 
const ll inf = 1e18 ;
const int mod = 1e9 + 7;
const int N = 3e5 + 5; 
const int SZ = 101;
ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

const int M = 1e4 + 1;

bool can_get(vector<int>& a, int x){
    if(a.empty()) return !x;
    bitset<2 * M + 5> bt; 
    bt[M] = 1; 
    for(int& x : a)   
        bt=(bt<<x)|(bt>>x);
    return bt[x + M];
}

void solve(){
    string s; int x , y;
    cin >> s >> x >> y ;
    reverse(all(s));
    while(!s.empty() && s.back() == 'F') --x , s.pop_back();
    if(s.empty()){
        cout <<(!x && !y ? "Yes\n" : "No\n" );
        return ;
    }
    reverse(all(s));
    
    vector<int> mv[2];
    int n = sz(s) , d = 0 , cur = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'T'){
            if(cur) mv[d].pb(cur);
            cur = 0;
            d ^= 1;
        }else cur++ ;
    }
    if(cur) mv[d].pb(cur);
    cout << ( can_get(mv[0], x) && can_get(mv[1] , y) ? "Yes\n" : "No\n" );
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC = 1, t = 0;
    // cin >> TC ;
    while(t++ < TC)
    {
        // cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}