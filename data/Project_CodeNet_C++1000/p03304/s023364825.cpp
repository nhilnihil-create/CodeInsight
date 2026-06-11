#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
	ll n,m,d;
	cin >> n >> m >> d;
	if(d == 0){
		printf("%.14lf\n",(double)(m-1)/n);
	}
	else{
		printf("%.14lf\n",(double)(m-1)*2*(n-d)/(n*n));
	}
}
