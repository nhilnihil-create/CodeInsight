  #include <bits/stdc++.h>
  using namespace std;

  typedef long long int ll;
  typedef pair<int,int> pi;
  typedef pair<ll,ll> pll;
  typedef vector<int> vi;
  typedef vector<ll> vll;
  typedef vector<pi> vpi;
  typedef vector<pll> vpll;

  #define  ff           first
  #define  ss           second
  #define  pb           push_back
  #define  IOS          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define  D(x)         cout << #x << " - " << x << endl;
  #define  D2(x)        cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]" << endl;
  #define  all(x)       (x).begin(), (x).end()
  #define  D2p(x)       cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << endl;
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 1e6 + 4;


  void solve(){
	  int n,m;
	  cin >> n >> m;
	  vector<vector<ll>>grid(n,vector<ll>(m));
	  vpi v;
	  vector<vi> ans;
	  for(int i=0;i<n;i++){
	  	  for(int j=0;j<m;j++){
	  	  		cin >> grid[i][j];
	  	  }
	  }
	  	int j = 0;
	  	int inc=1;
		for(int i=0;i<n;i++){
			for(;j<m && j>=0;j+=inc){
				// cout << (i+1)<<(j+1) << ' ';
				if(grid[i][j]%2){
					vi v;
					v.push_back(i);
					v.push_back(j);
					if(j+inc<m && j+inc>=0){
						grid[i][j+inc]+=1;
						v.push_back(i);
						v.push_back(j+inc);	
						ans.push_back(v);
					}
					else if(i+1<n){
						grid[i+1][j]+=1;
						v.push_back(i+1);
						v.push_back(j);
						ans.push_back(v);
					}
				}	
			}
			if(j==m){
				j--;
				inc = -1;
			}
			else{
				j++;
				inc = 1;
			}
			// cout << '\n';
		}
		cout << (int)ans.size() << '\n';
		for(int i=0;i<(int)ans.size();i++){
			for(int j=0;j<4;j++){
				cout << ans[i][j]+1;
				if(j<3)cout << ' ';
			}
			if(i<ans.size()-1)cout << '\n';
		}
	      
  }

  int main(){
    IOS
    solve();
    // cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
