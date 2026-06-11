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
	cin>>n;
	vector<string> words(n);
	set<string> dict;
	bool ans = true;
	for(int i = 0 ; i < n; i++){
		cin>>words[i];
		if( dict.count(words[i]) == 0){
			dict.insert(words[i]);
		}else{
			ans = false;
		}
	}
	for(int i = 1; i < n; i++){
		if( words[i-1][words[i-1].size()-1] != words[i][0]) ans = false;
	}
	if( ans == false){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
