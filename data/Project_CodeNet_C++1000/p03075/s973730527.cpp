#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll a[5];
	for(ll i=0; i<5; i++)
		cin >> a[i];
	ll k;
	cin >> k;
	sort(a, a+5);
	if(a[4] -a[0] > k)
		cout << ":(";
	else
		cout << "Yay!";
	return 0;
}