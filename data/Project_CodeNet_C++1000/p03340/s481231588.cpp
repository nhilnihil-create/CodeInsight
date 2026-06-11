#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s;
long long a[300100];
int main(){
    cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	long long suma=0,sumb=0,j=0,cnt=0;
	for(int i=1; i<=n; i++){
		while(j+1<=n&&((suma^a[j+1])==(sumb+a[j+1]))){
			sumb+=a[j+1];
			suma^=a[j+1];
			j++;
		}
		if(suma==sumb)
		  cnt+=j-i+1;
		suma^=a[i];
		sumb-=a[i];
	}
    cout<<cnt<<endl;
	return 0;
}
// 当a^b<a+b时，说明a跟b的二进制有重复，那么后面不管再异或多少，a^b^.. <a+b+...
// ^的优先级比==低！！！！！！要加括号！！！！maya,卡了好久
//还是尺取法，枚举左端点，同时移动右端点


