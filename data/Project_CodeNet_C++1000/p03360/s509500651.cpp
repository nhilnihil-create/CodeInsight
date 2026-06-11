#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int a, b, c, k; cin >> a >> b >> c >> k;
  	priority_queue<int> nums;
    nums.push(a);  nums.push(b);  nums.push(c);
  	while(k){
    	k--;
      	int max_num = nums.top();
      nums.pop();
      nums.push(max_num * 2);
    }
  
  int ans = 0;
  	while(!nums.empty()){
    	ans += nums.top();
      nums.pop();
    }
  cout << ans << endl;
    return 0;
}
