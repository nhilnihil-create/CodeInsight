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
	int n,h,w,a,b,cnt=0;
	cin>>n>>h>>w;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>=h&&b>=w){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

