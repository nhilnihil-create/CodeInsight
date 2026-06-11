	#include<bits/stdc++.h>

	using namespace std;
	#define ll                              long long
	#define int                             long long
	#define F                               first
	#define S                               second
	#define pb                              push_back

	#define mp                              make_pair
	#define pii                             pair<int,int>
	#define vii                             vector<int>
	#define vvii                            vector<vector<int>>
	#define mii                             map<int,int>
	#define umii                            unordered_map<int,int>
	#define pql                             priority_queue<int>
	#define pqs                             priority_queue<int,vi,greater<int>>
	#define setbits(x)                      __builtin_popcountll(x)
	#define zerobits(x)                     __builtin_ctzll(x)
	#define mod                             1000000007
	#define inf                             1e18
	#define ps(x,y)                         fixed<<setprecision(y)<<x
	#define mk(arr,n,type)                  type *arr=new type[n]
	#define w(t)                            int t;cin>>t;while(t--)
	#define rep(i,a,n)                      for(int i=a;i<n;i++)
	#define fio                             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
	#define SIZE                            1000001
	#define all(x)                          (x).begin(),(x).end()
	#define cunt                            continue

	  void muks()
		   {
		   //  fio;
		       #ifndef ONLINE_JUDGE
		           freopen("in.txt","r",stdin);
		           freopen("out2.txt","w",stdout);
		       #endif // ONLINE_JUDGE
		   }
      vector<vector<int>> generate(int numRows) {
        
         vector<vector<int>> ans(numRows);
        if(numRows==0) return ans;
         ans[0].push_back(1);
         for(int i=1;i<numRows;i++)
         { 
             vector<int> temp(i+1);
             temp[0]=1;
             for(int j=1;j<i;j++)
             {
                 temp[j]=ans[i-1][j]+ans[i-1][j-1];
             }
             temp[i]=1;
             ans[i]=temp;
         }
        return ans;
    }
    int N = 10001;
    vii prime(100001,1);
    void seive(){
    	prime[2]=1;
    	prime[3]=1;
    	prime[1]=0;
    	for(int i= 2;i*i<=N;i++){
    		if(prime[i]==0){
    			cunt;
    		}
    		for(int p=i*i;p<=N;p+=i){
                prime[p]=0;
    		}
    	}
    	return ;
    }
		

	int32_t main() {
	//code
		  muks();
		 /* int nt;
		  cin>>nt;
*/
		 // seive();

	     // for(int t1 =0;t1<nt;t1++) {
                
          int n;
          cin>>n;

          vii ar(n);
          rep(i,0,n) cin>>ar[i];

          vvii dp(n+1,vii(n+1,0));

          for(int i=2;i<=n;i++){
          	for(int left = 0;left+i<=n;left++){
          		int right = left + i - 1;
          		int sum =0;
          		for(int j = left;j<=right;j++){
          			sum+=ar[j];
          		}
          		dp[left][right] = 1000000000000000;
          		for(int j = left;j<right;j++){
          			dp[left][right] = min(dp[left][j]+dp[j+1][right]+sum,dp[left][right]);
          		}
          	}
          }

          cout<<dp[0][n-1]<<endl;







	   //   } 


	      } 
