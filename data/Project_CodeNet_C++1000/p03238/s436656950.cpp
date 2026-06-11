#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#include <iomanip>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int N;


int main(){
	cin.tie(0);
	cout.tie(0);

	ios::sync_with_stdio(false);
	cin >> N;
	if (N == 1) {
		cout << "Hello World" << endl;
	}
	else {
		int a, b;
		cin >> a >> b;
		cout << a + b<<endl;
	}

	
	return 0;
}
