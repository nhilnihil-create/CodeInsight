#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n ; 
ll inf = 1e18+7; 
long int arr[401]; 
vector< vector<ll> > memo(401 , vector<ll> (401,-1) );

ll find(int i ,int j )
{
     if( i == j ) return 0 ;

     if(memo[i][j] != -1 ) return memo[i][j];
     
     ll res = inf;
     ll sum = accumulate(begin(arr)+i, begin(arr)+ (j+1), 0ll ) ;  
     for(int k = i+1 ; k <= j ; k ++)
     {
     	
         res = min ( res , sum + find(i,k-1) + find(k,j));
     	
     }

     return memo[i][j] = res; 

}
void solve()
{
       
       cin >> n ;
       for(int i = 0; i < n ; i ++) cin >> arr[i];

       	cout << find(0,n-1); 
       


}

int main()
{

	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 
	 int test = 0, t = 1;
	 if(test) cin >> t;
	 for(int i = 0 ; i < t ; i ++)
	 {
         solve(); 
	 }

	return 0;
}
