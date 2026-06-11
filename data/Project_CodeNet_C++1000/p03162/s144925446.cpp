#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
//macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
int mod = 1e9+7;
// If wrong answer use LONG LONG instead on int
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
int a[100005][4];
int dp[100005][4];
int n;

int dfs(int day,int flag){
	if(day == n){
		return 0;
	}
	if(dp[day][flag] != -1){
		return dp[day][flag];
	}
	int maxi = 0;
	if(flag == 0){
		maxi = max(maxi,a[day][1] + dfs(day+1,1));
		maxi = max(maxi,a[day][2] +dfs(day+1,2));
		maxi = max(maxi,a[day][3] +dfs(day+1,3));
	}
	else if(flag == 1){
		maxi = max(maxi,a[day][2] +dfs(day+1,2));
		maxi = max(maxi,a[day][3] +dfs(day+1,3));
	}
	else if(flag == 2){
		maxi = max(maxi,a[day][1] +dfs(day+1,1));
		maxi = max(maxi,a[day][3] +dfs(day+1,3));
	}
	else{
		maxi = max(maxi,a[day][1] +dfs(day+1,1));
		maxi = max(maxi,a[day][2] +dfs(day+1,2));
	}
	dp[day][flag] = maxi;
	return maxi;
}

void solution(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j =1;j<=3;j++){
			cin >> a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans = dfs(0,0);
	cout << ans << endl;
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