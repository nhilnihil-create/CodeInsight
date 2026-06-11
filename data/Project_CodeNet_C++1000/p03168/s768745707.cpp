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

            double dp[3000][3000] , a[3000];
            int vis[3000][3000];

            double prob(int n, int h)
            {
            	if(vis[n][h]) return dp[n][h];

            	vis[n][h]=1;

            	if(n==0 || h>n )
            		return dp[n][h] = 0;
            	if(n==1)
            	{
            		if(h==1)
            			return dp[n][h]=a[n];
            		else
            			return dp[n][h]=(1-a[n]);
            	}
            	if(h==0)
            		return dp[n][h] = (double)prob(n-1,h)*(1-a[n]);
            	
            	
            	return dp[n][h] = prob(n-1,h)*(double)(1-a[n]) + prob(n-1,h-1)*(double)a[n];
            }

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
                    
                    int n;
                    cin>>n;

                    fori(i,1,n)
                    	cin>>a[i];

                    double sum=0;
                    fori(h,0,n)
                    {
                    	if(h>(n-h))
                    		sum+=prob(n,h);
                    }

                    /*fori(i,1,n)
                    {
                    	fori(j,1,n)
                    	{
                    		cout<<dp[i][j]<<" ";
                    	}
                    	cout<<"\n";
                    }*/
                    cout<<fixed<<setprecision(10)<<sum;
                    //cout<<prob(2,1);
                }
                cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";

                return 0;
            }
                            //              NOW IT'S TIME TO WAKE UP... 