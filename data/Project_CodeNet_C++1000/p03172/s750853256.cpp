#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int K = 100001;
const int mod = 1000000007; 

int arr[N];
int n,k; 


void solve()
{
       cin >> n >> k;
      
       //cout << " n " << n << " k " << k << endl; 
       for(int i = 0 ; i < n; i ++) cin >> arr[i]; 
        vector< int >  pre(k+2,0),t(k+2);
        
        pre[1] = 1 ; 
        
        auto print = [&]() 
        {
            for(int i = 0 ; i <= k+1 ; i ++)
               cout << pre[i] << " ";
            cout << endl; 
        };
        for(int i = 1 ; i <= n ; i ++ )
        {    
            
            // find the prefix sum. 
            for(int ii = 1 ; ii <= k+1 ; ii ++) pre[ii] = ( 0l + pre[ii]+pre[ii-1] ) % mod; 

            for(int j = 0; j <= k ; j ++)
            {
               // memo[i][j] = sum(memo[i-1][j-k]) for k = 0 to a[i].
               
               int l = j-min(j,arr[i-1]);
               t[j+1] = ( 0l + pre[j+1] - pre[l] + mod ) % mod ; 
    
               
                /**
               for(int k = 0 ; k <= min(j,arr[i]) ; k ++)
               {
                   memo[i][j] += memo[i-1][j-k]];
               }

               */

            }

            pre = t; 
            //print(); 
         
         }


        //print(); 
        cout << pre[k+1]; 
        //cout << find(0,k);
}

int main()
{

	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 solve();
	 return 0;
}