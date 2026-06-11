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
#include<string>
#include<stdlib.h>
#include<stdio.h>
typedef long long ll;

using namespace std;

int main(){	
	int a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d;
	e=c-d+b;
	f=d+c-a;
	g=a-d+b;
	h=b+c-a;
	cout<<e<<' '<<f<<' '<<g<<' '<<h;
}