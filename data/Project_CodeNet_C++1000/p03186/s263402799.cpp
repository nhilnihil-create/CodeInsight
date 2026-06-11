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
ll a,b,c;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >>a >>b >>c;
	ll res;
	if(a+b==c){
		res = a + 2 * b;
	}else if(a + b < c){
		res = a + 2 * b + 1;
	}else{
		res = b + c;
	}
	cout << res <<endl;
	return 0;
}
