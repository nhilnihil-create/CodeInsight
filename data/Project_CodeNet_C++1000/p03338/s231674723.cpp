#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	int ans = 0;
	for(int i = 0; i <n; i++){
		set<char> charCount;
		for(int j = 0; j <= i; j++){
			for(int k = i + 1; k < n; k++){
				if( s[j] == s[k]) charCount.insert(s[j]);
			}
		}
		ans = max(ans,(int)charCount.size());
	}
	cout<<ans<<endl;
	return 0;
}
