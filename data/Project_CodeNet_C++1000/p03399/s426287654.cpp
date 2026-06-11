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
	int a,b,c,d,w1,w2;
	cin>>a>>b>>c>>d;
	w1=min(a,b);
	w2=min(c,d);
	cout<<w1+w2<<endl;

	return 0;
}
