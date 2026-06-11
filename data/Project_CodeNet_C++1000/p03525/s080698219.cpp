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

using namespace std;

int n;
int d[52];

bool solve(int diff){
	int st=0;
	int tmp[50];
	tmp[0] = 0;
	for(int i=1;i<=n;i++){
		if(abs(d[st]-d[i]) < diff){
			tmp[i] = 24-d[i];
		} else {
			tmp[i] = d[i];
			st = i;
		}
	}
	tmp[n+1] = 24;
	sort(tmp,tmp+n+2);
	for(int i=1;i<=n+1;i++){
		if(abs(tmp[i-1]-tmp[i]) < diff) return false;
	}
	return true;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>d[i];
	d[n]=0;
	d[n+1]=24;
	sort(d,d+n+2);

	int ans = 0;
	for(int i=24;i>=0;i--){
		if(solve(i)){
			ans = i;
			break;
		}
	}

	cout<<ans<<endl;

	return 0;

}