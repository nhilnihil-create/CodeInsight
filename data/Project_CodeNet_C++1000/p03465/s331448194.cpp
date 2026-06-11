#include<cstdio>
#include<bitset>
using namespace std;
bitset<4000020>s;
int n,a,i,sum;
int main(){
	s[0]=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		sum+=a;
		s|=s<<a;
	}
	for(i=sum+1>>1;i<=sum;i++)
	if(s[i]){
		printf("%d",i);
		return 0;
	}
}