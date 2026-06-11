#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip> 
#include <cstring>
#include <queue>
#include <stack> 
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
ll n,H,W,x,y;
ll cnt = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >>H >>W;
	while(n--){
		cin >> x >>y;
		if(x >= H &&y >= W){
			cnt++;
		}
	}
	cout <<cnt <<endl;
	return 0;
}