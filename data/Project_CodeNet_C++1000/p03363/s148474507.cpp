#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define INF 2147483647
#define LLINF 9223372036854775807
using namespace std;
map<long long,long long> mp;
int main(){
	int n;
	cin>>n;
	mp[0]++;
	long long cnt=0;
	long long t;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>t;
		ans+=t;
		cnt+=mp[ans];
		mp[ans]++;
	}
	cout<<cnt<<endl;
	return 0;
}