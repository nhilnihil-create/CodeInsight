#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#define long long
using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	if(a+b>=c-1){
		cout<<c+b;
	}
	else{
		cout<<a+b+1+b;
	}
}
