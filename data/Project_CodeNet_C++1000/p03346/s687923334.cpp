//agc024_b.cpp
//Thu Jul  9 22:33:11 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n];
	int q[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
		a[i]--;
		q[a[i]] = i;
	}

	int count = 1;
	int ans = 1;
	for (int i=1;i<n;i++){
		if (q[i]>q[i-1]){
			count++;
		}else {
			count = 1;
		}
		ans = max(ans,count);
	}


	cout << n-ans << endl;
//	printf("%.4f\n",ans);
}