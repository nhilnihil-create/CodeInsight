#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
double pi=4*atan(1);

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b)cout<<c<<"\n";
	else if(b==c)cout<<a<<"\n";
	else cout<<b<<"\n";
	return 0;
}