#include<iostream>
#include<cstdio>
#include <set>
using namespace std;
long long ans1,ans2,x,y,A,B,C,D,t;
set<long long> s;
bool check(long long a,long long b,long long c,long long d) {
	if(d<b)return false;
	if(a<b)return false;
	if(b<c)return true;
	a= a-((a-c+b-1)/b)*b;
	if(a<0||a>c)return false;
	if(d%b==0)return true;
	s.clear();
	while(!s.count(a)){
		//cout << a << endl;
		if(a<0||a>c)return false;
		s.insert(a);
		a=a+((c-a)/(d%b)+1)*(d%b)-b;
	}
	return true;
}
int main() 
{	
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		if(check(A,B,C,D))printf("Yes\n");
		else printf("No\n");
	}
	
}