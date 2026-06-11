#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll isPrime(int n) 
{ 
	// Corner cases 
	if (n <= 1) 
		return 1; 
	if (n <= 3) 
		return 2; 

	// This is checked so that we can skip 
	// middle five numbers in below loop 
	if (n % 2 == 0 || n % 3 == 0) 
		return 1; 

	for (int i = 5; i * i <= n; i = i + 6) 
		if (n % i == 0 || n % (i + 2) == 0) 
			return 1; 

	return 2; 
} 

ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i,res%=1000000007; 
    return res; } 
 
 int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
 
ll findlcm(ll arr[], int n) 
{ 
   
    ll ans = arr[0]; 
  
    
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
 
 
int main() 
{
    fast;
    ll t=1;
    //cin>>t;
    while(t--)
    {
      ll h,w,k;
      cin>>h>>w;
      string A[h];
      ll B[h][w]={0};
      
          for(ll j=0;j<h;j++)
          {
              cin>>A[j];
              //cout<<A[j];
          }
          //cout<<endl;
      
      for(ll i=0;i<h;i++)
      {
          for(ll j=0;j<w;j++)
          {
              if(A[i][j]!='#')
              {
                  k=0;
                if(i!=0 && A[i-1][j]=='#' )
                {
                    k++;
                }
                if(i!=h-1 && A[i+1][j]=='#')
                {
                    k++;
                }
                if(j!=0 && A[i][j-1]=='#' )
                {
                    k++;
                }
                if(j!=w-1 && A[i][j+1]=='#')
                {
                    k++;
                }
                if((i!=0 && j!=0) && A[i-1][j-1]=='#')
                {
                    k++;
                }
                if((i!=0 && j!=w-1) && A[i-1][j+1]=='#' )
                {
                    k++;
                }
                if((i!=h-1 && j!=0) && A[i+1][j-1]=='#')
                {
                    k++;
                }
                if((i!=h-1 && j!=w-1) && A[i+1][j+1]=='#')
                {
                    k++;
                }
                B[i][j]=k;
                //cout<<k<<" ";
              }
          }
      }
      for(ll i=0;i<h;i++)
      {
          for(ll j=0;j<w;j++)
          {
            if(A[i][j]=='#')
              cout<<'#';
            else
              cout<<B[i][j];
          }
          cout<<endl;
      }
      
    } 
    return 0;
}
