//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;
// const int imax = 100000;

int main(){
	string s;
	cin >> s;
	int y,m,d;
	y = stoi(s.substr(0,4));
	m = stoi(s.substr(5,2));
	d = stoi(s.substr(8,2));
	if(y < 2019){
		printf("Heisei\n");
		return 0;
	}else if (y == 2019){
		if(m < 5){
			printf("Heisei\n");
			return 0;
		}
	}
	printf("TBD\n");
	return 0;
}
