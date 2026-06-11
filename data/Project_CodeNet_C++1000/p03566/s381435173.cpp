#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int v[200005];
int t[105];
int vv[205];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	m=0;
	for(i=0;i<n;i++){
		cin>>t[i];
		m+=t[i];
	}
	for(i=0;i<=m;i++){
		v[i]=min(i,m-i);
	}
	b=0;
	for(i=0;i<n;i++){
		cin>>a;
		for(j=0;j<=m;j++){
			if(j<b)c=a+b-j;
			else if(j<=b+t[i])c=a;
			else c=a+j-(b+t[i]);
			v[j]=min(v[j],c);
		}
		vv[i]=a;
		b+=t[i];
	}
	double s=0;
	b=0;
	//array_show(v,100);
	for(i=0;i<n;i++){
		for(j=b;j<b+t[i];j++){
			s+=(v[j]+v[j+1])/2.;
			if(v[j]==v[j+1] && v[j]!=vv[i])s+=1./4;
		}
		b+=t[i];
	}
	cout<<fixed<<setprecision(12)<<s<<endl;
}