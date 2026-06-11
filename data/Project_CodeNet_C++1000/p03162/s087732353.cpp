/* Author : Harshit Jain a.k.a. iharshit009 */
#include <bits/stdc++.h>
#define vi               vector<int>
#define pb(x)            push_back(x)
#define all(x)           x.begin(), x.end()
#define sortall(x)       sort(all(x))
#define sortrev(x)       sort(all(x), greater<int>())
#define debug(x)         cout << '>' << #x << ':' << x << endl;
#define int              long long
#define ld               long double
#define endl 			 "\n";
#define mp 				 make_pair
#define pii 			 <int, int>
#define lb 				 lower_bound
#define ub				 upper_bound
#define len(a)           int((a).size())
#define prec(n)          fixed<<setprecision(n)
#define cnt(n)           __builtin_popcountll(n)
#define pi               pair<int, int>
const int mod = 1000000007;
using namespace std;
using namespace std::chrono;
const int N = 1e5 + 5; 
int n;
int a[N][4];
int dp[N][4];


int func(int day, int flag){
	if(day == n)return 0;
	if(dp[day][flag] != -1) return dp[day][flag];
	int maxi = 0;
	if(flag == 0){
		maxi = max(maxi, a[day][1] + func(day + 1, 1));
		maxi = max(maxi, a[day][2] + func(day + 1, 2));
		maxi = max(maxi, a[day][3] + func(day + 1, 3));
	}
	else if(flag == 1){
		maxi = max(maxi, a[day][2] + func(day+1, 2));
		maxi = max(maxi, a[day][3] + func(day+1, 3));
	}
	else if(flag == 2){
		maxi = max(maxi, a[day][1] + func(day+1, 1));
		maxi = max(maxi, a[day][3] + func(day+1, 3));

	}
	else{
		maxi = max(maxi, a[day][1] + func(day+1, 1));
		maxi = max(maxi, a[day][2] + func(day+1, 2));
	}
	return dp[day][flag] =  maxi;
}



int32_t main(){
auto start = high_resolution_clock::now(); // starting clock
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t;
t = 1;
// cin >>t;q
while(t--){

// int n;
cin >>n;
memset(dp,-1,sizeof(dp));
for(int i = 0; i<n; i++){
	for(int j = 1; j<4; j++){
		cin >> a[i][j];
	}
}
cout << func(0,0);





// when app updates how does the data remains in the app, and not changes in the activities, but add additional features and why does app restarts after it gets updated



}
auto stop = high_resolution_clock::now(); // stop clock
auto duration = duration_cast<microseconds>(stop - start);  // printing duration
cerr << "Time taken by function: " << duration.count() << " milliseconds" << endl; 
return 0;
}