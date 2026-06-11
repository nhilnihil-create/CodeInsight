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
	string s,t;
	cin>>s;
	cin>>t;
	int n = s.size();
	bool ans;
	for(int i = 0; i < n; i ++){
		ans = true;
		for(int j = 0; j < n; j++){
			if( s[ (i + j) % n] != t[j]){
				ans = false;
				break;
			}
		}
		if( ans == true){
			break;
		}
	}
	if(ans == true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
