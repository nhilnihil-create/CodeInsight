#include<cstdio>
int main(){
	int q;
	scanf("%d",&q);
	for(int x=0;x<q;x++){
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a>b){
			long long int c=b;
			b=a;
			a=c;
		}
		//a<=b
		long long int ans=0;
		ans+=a-1;
		if(a==b){
			ans+=a-1;
		}else{
		for(long long int i=a;0==0;i++){
			if(i*i>=a*b-1){
				int x=i-1;
				if(i*i==a*b-1)x++;
				if((a*b-1)/x==x){
					ans+=(2*x-a-1);
				}else{
					ans+=(2*x-a);
				}
				break;
			}
			if((i+100)*(i+100)<a*b-1){
				i+=100;
			}
		}
		}
		printf("%lld\n",ans);
	}
	return 0;
}