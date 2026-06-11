                                                //  IT'S NEVER TOO LATE...

            #include <bits/stdc++.h>
            #include <complex>
            #define ll long long

            #define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
            #define forn(i, n) fore(i, 0, n)
            #define fori(i, l, r) fore(i, l, (r) + 1)
            #define sz(v) int((v).size())
            #define all(v) (v).begin(), (v).end()
            #define pb push_back
            #define mp make_pair
            #define ff first
            #define ss second
			#define ms(m) memset(m,0,sizeof(m))
            
            //#define C complex<int>
            #define X real()
            #define Y imag()

            using namespace std; 

            const double PI = atan(1)*4;
            #define inf 1e9
            const int mod=1e9+7;


            /*struct matrix
            {
                int k;
                vector<vector<ll>> data;
                matrix(int x)
                {
                    k=x;
                    data.resize(x);
                    forn(i,x)
                    data[i].resize(x);
                }

                matrix operator *(matrix m1)
                {
                    int n=m1.data.size();
                    matrix m2(n);

                    forn(i,n)
                    {
                        forn(j,n)
                        {
                            forn(k,n)
                            {
                                m2.data[i][k]+=((m1.data[i][j]%1000000007)*(data[j][k]%1000000007))%1000000007;
                                m2.data[i][k]%=1000000007;
                            }
                        }
                    }


                    return m2;
                }
            };*/


            /*ll dp[30][30],val[100],wt[100];
            ll fpair(ll n,ll k)
            {
                if(n==0 || n<k)
                    return 0;
                if(n==k)
                	return 1;
                if(dp[n][k])
                    return dp[n][k];
                
                return dp[n][k]=(ll)fpair(n-1,k-1) + (ll)k*fpair(n-1,k);
            }*/

            
            int main()
            {

            	#ifndef ONLINE_JUDGE
	            freopen("input.txt","r", stdin);
	            freopen("output.txt", "w", stdout);
	            #endif
            
                ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
             
                int tt=1;
                //cin>>tt;

                while(tt--)
                {
                    //matrix mat(n),m2(n);
                    
                	  ll n,k;
					  cin>>n>>k;
					  ll a[n+5];
					  for(ll i=1;i<=n;i++)
					      cin>>a[i];
					  ll dp[n+1][k+1];
					  ms(dp);
					  dp[0][0]=1;
					  for(int i=1;i<=n;i++)
					  {
					    ll pref[k+1];
					    ms(pref);
					    pref[0]=dp[i-1][0]%mod;
					    fori(j,1,k)
					      pref[j]=(pref[j-1]+dp[i-1][j])%mod;
					    forn(j,k+1)
					    {
					      if(j<=a[i])
					        dp[i][j]=pref[j]%mod;
					      else dp[i][j]=(pref[j]-pref[j-a[i]-1]+mod)%mod;
					    }
					  } 
					 
					  cout<<dp[n][k]<<endl; 
                }
                cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";

                return 0;
            }
                            //              NOW IT'S TIME TO WAKE UP... 