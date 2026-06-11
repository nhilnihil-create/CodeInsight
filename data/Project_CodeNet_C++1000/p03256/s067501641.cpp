    /* Just_Do_It ___________ICARUS__________________*/
                     
    #include <bits/stdc++.h>
    using namespace std;
           
    typedef long long ll;
    #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define rep(i,a,n) for(ll i=a;i<n;i++)
    #define per(i,n,a) for (ll i=n;i>a;i--)
    #define te ll t; std::cin >> t; while(t--)
    #define SZ 200010
    //# define M_PIl  3.141592653589793238462643383279502884L 
    /*   Proceed with CAUTION   */
     
     vector<ll> g[SZ];
     ll in[SZ],num[SZ][2];

    int main(){
        fastio;
        ll n,m; string s;
        cin>>n>>m>>s;
        s = '0'+s;
        while(m--){
        	ll x,y;
        	cin>>x>>y;
        	g[x].push_back(y);
        	g[y].push_back(x);
        	++num[x][s[y]=='B'];
        	++num[y][s[x]=='B'];
        }
        queue<ll> q;
        rep(i,1,n+1) if(num[i][0]==0 || num[i][1]==0) q.push(i), in[i]=1;
        while(!q.empty()){
        	ll x = q.front(); q.pop();
        	for(auto i:g[x]){
        		if(!in[i] && !--num[i][s[x]=='B']){
        			q.push(i);
        			in[i]=1;
        		}
        	}
        }
        rep(i,1,n+1) if(!in[i]) return puts("Yes"),0;
        puts("No");
        }

