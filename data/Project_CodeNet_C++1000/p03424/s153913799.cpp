#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	set<char> colors;
	for(int i = 0; i < n;i++){
		char c;
		cin>>c;
		if( colors.count(c) == 0){
			colors.insert(c);
		}
	}
	if( colors.size() == 3){
		cout<<"Three"<<endl;
	}else{
		cout<<"Four"<<endl;
	}
	return 0;
}

