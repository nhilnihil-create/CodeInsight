#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;
	int a,b,c;
	a=b=c=0;
	for (char ch :s){
		if (ch=='a')a++;
		else if (ch=='b')b++;
		else c++;
	}

	int n = (s.size()+2)/3;
	int m = s.size()/3;
	//cout << a << ' ' << b << ' ' << c << ' ' << n << ' '<<m<<endl;
	cout << (m<=a && a<=n && m<=b && b<=n && m<=c && c<=n?"YES":"NO")<<endl;


	return 0;
}