#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mx INT_MAX
#define mn INT_MIN
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define itr set<int> :: iterator
const int N = 1e5+10;

int dp[100001];

int main(){

  // **** START HERE ****
       
   int n, k;
   cin>>n>>k;
   
   vector<int> a;
   for(int i=0; i<n; i++){
   	int x;
   	cin>>x;
   	a.pb(x);
   }

   memset(dp, 0, sizeof(dp));

   for(int i=1; i<=k; i++){
   	for(int j=0; j<n; j++){
   		if(i- a[j] < 0)
   			break;
   		if(dp[i-a[j]] == 0){
   			dp[i] = 1;
   			break;
   		}
   		
   	}
   }

   if(dp[k] == 1)
     cout<<"First"<<endl;
   else
   	 cout<<"Second"<<endl;

//   **** END HERE ****
    
    return 0;
}