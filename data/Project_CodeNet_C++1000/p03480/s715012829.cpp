#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#include <sstream>
#include <istream>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll;

int main(){
	char s[100001];
	cin >> s;

	int n = strlen(s);
	int ans = 100000;
	if(n==1){
		ans = 1;
	}else{
		for(int i=1;i<n;i++){
			int tmp = 100000;
			if(s[i-1]!=s[i]){
				tmp = max(n-i,i);
			}
			ans = min(ans,tmp);
		}
	}
	if(ans==100000){
			cout << n << endl;
		}else{
			cout << ans << endl;
		}

	return 0;
}
