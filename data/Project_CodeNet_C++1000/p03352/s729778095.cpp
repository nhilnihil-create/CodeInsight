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
	int x;
	cin>>x;
	int ans = 1;
	for(int i = 2; i*i <= x; i++){
		for(int p = 2; pow((double)(i),p) <= x; p++){
			ans = max(ans,(int)pow((double)(i),p));
		}
	}
	cout<<ans<<endl;
	return 0;
}

