#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int Q;
	long long int a, b1, b, s, ans;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		scanf("%lld %lld", &a, &b);
		if(a<b){
			b1=b;
			b=a;
			a=b1;
		}
		long long int s1=b-1, s2=a+1;
		while(s1!=s2){
			long long int smid=(s1+s2+1)/2;
			if(smid*smid<a*b){
				s1=smid;
			}else{
				s2=smid-1;
			}
		}
		s=s1;
	
		if(a==b){
			ans=2*(b-1);
		}else if(a==b+1){
			ans=2*b-2;
		}else if(a==b+2){
			ans=2*b-1;
		}else if(a==4 && b==1){
			ans=1;
		}else if(s*(s+1)<a*b){
			ans=2*s-1;
		}else{
			ans=2*s-2;
		}
		printf("%lld\n", ans);
	}
	return 0;

}