#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
typedef vector<int> vi;
//macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
int mod = 1e9+7;
/////////////////////////////////////////////////////////////SEGMENT  TREES////////////////////////////////////////////////
// const int N = 100000;  
// int n;
// int tree[2 * N]; 

// void build( int arr[])  
// {   
//     for (int i=0; i<n; i++) // insert leaf nodes in tree     
//         tree[n+i] = arr[i]; 
       
//     for (int i = n - 1; i > 0; --i) // build the tree by calculating parents add function here      
//         tree[i] = tree[i<<1] + tree[i<<1 | 1];     
// } 

// void updateTreeNode(int p, int value)  
// {   
//     tree[p+n] = value; 
//     p = p+n;

//     for (int i=p; i > 1; i >>= 1) 
//         tree[i>>1] = tree[i] + tree[i^1]; 
// } 
  
// // function to get sum on interval [l, r) 
// int query(int l, int r)  
// {  
//     int res = 0; 
      
//     // loop to find the sum in the range 
//     for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
//     { 
//         if (l&1)  
//             res += tree[l++]; 
      
//         if (r&1)  
//             res += tree[--r]; 
//     } 
      
//     return res; 
// }

/////////////////////////////////////////////////////**********************/////////////////////////////////////////////////

// int gcd(int a,int b){
// 	if(b == 0){
// 		return a;
// 	}
// 	return gcd(b,a%b);
// }

void solution(){
	ll n,k;
	cin >> n >> k;
	vector<ll> nums(n);
	for(ll& x : nums){
		cin >> x; 
	}
	vector<ll> dp(n,INT_MAX);
	dp[0] = 0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			dp[i] = min(dp[i],(i-j >=0 ? (dp[i-j]+abs(nums[i] - nums[i-j])) : INT_MAX));
		}
	}
	cout << dp[n-1] << endl;
	return;
}
 
 
// void solution(){ //read a whole line from the input, possibly containing spaces
// 	string s;
// 	getline(cin,s);
// }
int main(){
	
    fio; // fast input output
    int t;
    t = 1;
    // cin >> t;
    while(t--){
    	// cout << "Case #" << t  << ": ";
        solution();
    }
    return 0;
};