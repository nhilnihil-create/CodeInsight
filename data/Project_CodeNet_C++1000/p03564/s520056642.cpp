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
	int n,k;
	cin>>n;
	cin>>k;
	int ans = 1;
	for(int i = 0; i < n; i++){
		if( k <= ans){
			ans = ans + k;
		}else{
			ans = ans + ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}

