#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=200*1000;
int a[L];
int b[L];
int s[L];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<N;i++){
		scanf("%d",b+i);
	}
	int r=0;
	for(int p=0;p<29;p++){
		int u=1<<p;
		for(int i=0;i<N;i++){
			s[i]=a[i]%(2*u);
		}
		sort(s,s+N);
		int c=0;
		for(int i=0;i<N;i++){
			int v=b[i]%(2*u);
			int z=lower_bound(s,s+N,2*u-v)-lower_bound(s,s+N,u-v);
			int y=lower_bound(s,s+N,4*u-v)-lower_bound(s,s+N,3*u-v);
			/*
			if(p==3){
				cerr << v << ": " << z << ", " << y << endl;
			}
			*/
			c+=z+y;
			c%=2;
		}
		//cerr << u << ", " << c << endl;
		r+=c%2*u;
	}
	printf("%d\n",r);


	return 0;
}

