#include<bits/stdc++.h>
using namespace std;
int jishu[100001],qian[100001];
int zs(int a){//输入一个数a，运行完毕后在数组里有小于a的质数，返回小于a的质数的个数 
	int sum=0;
	int i,j;
	for(i=2;i<=sqrt(a);i++){
		if(jishu[i]==0) continue;
		for(j=i*2;j<=a;j+=i){
			jishu[j]=0;
		} 
	}
	return sum;
}
int main(){
	for(int i=1;i<=100000;i++) jishu[i]=1;
	zs(100000);
	jishu[1]=0;
	int n;
	cin>>n;
	qian[1]=0;
	for(int i=2;i<=100000;i++){
		if(jishu[i]&&jishu[(i+1)/2])
			qian[i]=qian[i-1]+1;
		else
			qian[i]=qian[i-1];
	}
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",qian[b]-qian[a-1]);
	}
	return 0;
}