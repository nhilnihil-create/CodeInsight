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
long long a[10010];
long long b[10010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	long long cnt=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(b[i]-a[i]<0)ans+=a[i]-b[i];
		else if(b[i]-a[i]>0)cnt+=(b[i]-a[i])/2;
	}
	if(ans<=cnt)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}