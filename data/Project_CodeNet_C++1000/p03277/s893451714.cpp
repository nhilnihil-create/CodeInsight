#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int LL;
vector<LL> v1;
LL t[100005];

int BIT[200007];
const int N=100002;

void bit_add(int t,int a,int n){//place,add,n
	for(int i=t+1;i<=n;i+=(i&(-i))){
		BIT[i-1]+=a;
	}
}

void bit_init(int n,int *a){//配列ごと加算
	for(int i=0;i<n;i++){
		bit_add(i,a[i],n);
	}
}

int bit_sum(int t){
	int s=0;
	for(int i=t+1;i!=0;i-=(i&(-i))){
		s+=BIT[i-1];
	}
	return s;
}

int main(){
	LL n;
	int i,j,k;
	int m[3];
	int a,b,c;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		v1.push_back(t[i]);
	}
	if(n==1){
		cout<<t[0]<<endl;
		return 0;
	}
	sort(v1.begin(),v1.end());
	m[0]=-1,m[1]=n;
	while(m[1]-m[0]>1){
		m[2]=(m[0]+m[1])/2,a=N,s=0;
		memset(BIT,0,sizeof(BIT));
		for(i=0;i<n;i++){
			bit_add(a,1,N*2);
			if(t[i]>=v1[m[2]])a++;
			else a--;
			s+=bit_sum(a);
		}
		if(s>=n*(n+1)/4)m[0]=m[2];
		else m[1]=m[2];
	}
	if(m[0]==-1)m[0]=0;
	cout<<v1[m[0]]<<endl;
	return 0;
}
		
	
