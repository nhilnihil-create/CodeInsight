//arc095_d.cpp
//Sat Aug 25 16:36:55 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a,a+n);

	int ans = a[n-2];
	for (int i=n-3;i>=0;i--){
		if (abs(a[n-1]/2-a[i])<abs(a[n-1]/2-ans)){
			ans = a[i];
		}
	}

	cout << a[n-1] << " " << ans << endl;
}