#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s.substr(i,1)=="x"){
			cnt++;
		}
	}
	if(s.length()>=8 && cnt>=8){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
	return 0;
}

