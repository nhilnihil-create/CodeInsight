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
	int n,cr=0,cb=0;
	string s,w;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s.substr(i,1)=="R"){
			cr++;
		}else{
			cb++;
		}
	}
	if(cr>cb){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}

