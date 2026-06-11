#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define TEST(A) cout <<A<<endl;
unordered_multiset<long long int>fact(long long int n){
	unordered_multiset<long long int>ret;
	long long int a=2;
	while (a*a<=n){
		while (n%a==0){
			n/=a;
			ret.insert(a);
		}
		a++;
	}
	return ret;
}
int main(){
long long int n,p;
cin >>n>>p;
if (n==1){
	cout <<p;
	return 0;
}
if (n>=40){
	cout <<"1"<<endl;
	return 0;
}
long long int ans=1;
auto l=fact(p);
long long int cnt=0;
for (long long int i=1;p>=pow(i-1,n);++i)
	cnt=i;
rep(i,cnt){
	long long int tmp=l.count(i);
	if(tmp>=n)
		ans*=pow(i,tmp/n);
}
cout <<ans<<endl;
}
