#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int a[200010];
bool vis[200010];
map<int,int> mp;
int mnmi(int x){
	int cnt=1;
	while(cnt<=x){
		cnt*=2;
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++)mp[a[i]]++;
	int ans=0;
	for(int i=0;i<n;i++){
		if(!mp[a[i]])continue;
		mp[a[i]]--;
		int j=mnmi(a[i])-a[i];
		if(mp[j]){
			ans++;
			mp[j]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}