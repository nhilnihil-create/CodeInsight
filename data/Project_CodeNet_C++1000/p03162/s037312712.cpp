#include<iostream>
using namespace std;

#define ll long long 

ll n,k;
const ll N = 100005;
//ll a[100005];
//ll dp[100005];
const ll Inf = 1e10;

ll ht[3][N];

ll dp[3][N];

ll maxhappiness(ll day, ll prevchoice){
	if(day == n)
      return 0;
  
  	if(dp[prevchoice][day] != -1){
    	return dp[prevchoice][day];
    }
 
  
  	int ans1,ans2;
  	ans1 = ans2 = 0LL;
  	
  	if(prevchoice == 0){
      ans1 = ht[1][day] + maxhappiness(day+1,1);
      ans2 = ht[2][day] + maxhappiness(day+1,2);
    }
  	else if(prevchoice == 1){
      ans1 = ht[0][day] + maxhappiness(day+1,0);
      ans2 = ht[2][day] + maxhappiness(day+1,2);
    }
  	else{
      ans1 = ht[0][day] + maxhappiness(day+1,0);
      ans2 = ht[1][day] + maxhappiness(day+1,1);
    }
  
  	return dp[prevchoice][day] = max(ans1,ans2);
}

int main(){
	cin >> n;
  	for(int i = 0; i < n; i++){
    	cin >> ht[0][i] >> ht[1][i] >> ht[2][i];
    }
  	for(int i = 0; i < n; i++){
    	dp[0][i] = dp[1][i] = dp[2][i] = -1;
    }
 	
  	auto ans1 = maxhappiness(0,0);
  	auto ans2 = maxhappiness(0,1);
  	auto ans3 = maxhappiness(0,2);
    //cout << ans1 << " " << ans2 << " " << ans3 << endl;
  	cout << max(ans1,max(ans2,ans3)) << endl;
    return 0;
}
