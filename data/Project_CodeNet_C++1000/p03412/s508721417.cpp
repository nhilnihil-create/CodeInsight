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
#include<cassert>
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

int t[2][220000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d;
	int s=0;
	vector<int> v1;
	cin>>n;
	for(j=0;j<2;j++){
		for(i=0;i<n;i++){
			cin>>a;
			t[j][i]=a;
		}
	}
	for(i=0;i<=28;i++){
		a=(1<<i+1)-1,d=0;
		v1.clear();
		for(j=0;j<n;j++){
			b=a&t[0][j];
			v1.push_back(b);
			v1.push_back(b+(1<<i+1));
		}
		sort(v1.begin(),v1.end());
		for(j=0;j<n;j++){
			if(t[1][j]&(1<<i)){
				b=(3<<i)-(t[1][j]&a);
				c=(1<<i+2)-(t[1][j]&a);
			}else{
				b=(1<<i)-(t[1][j]&a);
				c=(1<<i+1)-(t[1][j]&a);
			}
			auto itr1=lower_bound(v1.begin(),v1.end(),b),itr2=lower_bound(v1.begin(),v1.end(),c);
			d+=distance(itr1,itr2);
			d%=2;
		}
		if(d%2==1)s+=1<<i;
	}
	cout<<s<<endl;
}