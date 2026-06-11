#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
#define INF 1e9;


int main()
{
	string str;
	int n;
	cin>>n;
	cin>>str;
	int *westLeft = new int [n+2];
	int *eastRight = new int [n+2];
	for(int i = 0; i < n+2; i++){
		westLeft[i] = 0;
		eastRight[i] = 0;
	}
	for(int i = 0; i < n; i++){
		if(str[i] == 'W'){
			westLeft[i+2] = westLeft[i+1] + 1;
		}else{
			westLeft[i+2] = westLeft[i+1];
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(str[i] == 'E'){
			eastRight[i] = eastRight[i+1] + 1;
		}else{
			eastRight[i] = eastRight[i+1];
		}
	}
	/*for(int i = 0; i < n + 2; i++){
		cout<<eastRight[i]<<" ";
	}
	cout<<endl;*/
	int ans = INF;
	for(int i = 1; i <= n+1; i++){
		ans = min(ans, westLeft[i] + eastRight[i]);
	}
	cout<<ans<<endl;
	return 0;
}

