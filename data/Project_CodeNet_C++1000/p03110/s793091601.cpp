#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int n;
	cin>>n;
	int jpy=0;double btc=0;
	fori(n){
		double x;string s;
		cin>>x>>s;
		if(s=="JPY"){
			jpy+=x;
		}else{
			btc+=x;
		}
	}

	cout<<fixed<<setprecision(7)<<(jpy+btc*380000);
}