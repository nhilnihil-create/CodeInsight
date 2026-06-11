#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int dp[100001];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i <= 100000; i++) dp[i] = MOD;

	dp[0] = 0; 
	for (int i = 0; i <= 100001; i++){
		if (dp[i] != MOD){
			for (int j = 0; j <= 7; j++){
				if (i + (int)pow(6, j) <= 100000){
					dp[i+(int)pow(6, j)] = min(dp[i+(int)pow(6, j)], dp[i] + 1); 
				}
			}
			for (int j = 1; j <= 6; j++){
				if (i + (int)pow(9, j) <= 100000){
					dp[i+(int)pow(9, j)] = min(dp[i+(int)pow(9, j)], dp[i] + 1);
				}
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}