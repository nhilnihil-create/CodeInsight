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
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>=c){
		cout<<b+c<<endl;
	}else{
		cout<<b+c - (c-(a+b+1))<<endl;
	}
	return 0;
}

