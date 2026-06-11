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
typedef long long ll;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int temp = i;
		int num = 0;
		while(temp > 0){
			num += temp % 10;
			temp /= 10;
		}
		if( a <= num && num <= b){
			ans += i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

