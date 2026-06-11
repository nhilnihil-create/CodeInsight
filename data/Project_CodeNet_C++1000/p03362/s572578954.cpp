#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define N 1000005
int su[N],cnt;
int n;
bool isprime[N];
void prime(){
    cnt=1;
    memset(isprime,1,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=0;//0和1不是素数
    for(int i=2;i<=N;i++){
        if(isprime[i])
            su[cnt++]=i;//保存素数i
        for(int  j=1;j<cnt&&su[j]*i<N;j++){
            isprime[su[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}
vector<int> v;
signed main(){
	prime();
	for(int i=1;i<cnt;i++){
		if(su[i]%10==1){
			v.push_back(su[i]);
			//if(v.size()==55) cout<<su[i]<<'\n';
		}
	}	
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;
}