#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
long long n, a, b;

int main() {
	scanf("%lld %lld %lld",&n,&a,&b);
	if(a>n || b>n) {
		puts("-1");
		return 0;
	}
	if(a+b-1>n || (n+b-1)/b>a) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		v.push_back(i);
	reverse(v.begin(),v.begin()+b);
	if(a==1) {
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		puts("");
		return 0;
	}
	int need=(n-b)%(a-1);
	for(int i=b;i<v.size();) {
		if(need) {
			reverse(v.begin()+i,v.begin()+i+(n-b)/(a-1)+1);
			need--;
			i+=(n-b)/(a-1)+1;
		} else {
			reverse(v.begin()+i,v.begin()+i+(n-b)/(a-1));
			i+=(n-b)/(a-1);
		}
	}
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	puts("");
	return 0;
}