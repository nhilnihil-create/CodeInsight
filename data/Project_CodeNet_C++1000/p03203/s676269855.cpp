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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
 
 
void array_show(int *a,int n){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?' ':'\n'));
}
void array_show(LL *a,int n){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?' ':'\n'));
}
 
vector<P> v1;
 
int main(){
	int h,w,n;
	int i,j,k;
	int a,b,c,s;
	int dis=0;
	cin>>h>>w>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(make_pair(a,b));
	}
	sort(v1.begin(),v1.end());
	s=h;
	for(i=0;i<n;i++){
		a=v1[i].first-v1[i].second;
		if(a<dis)continue;
		if(a==dis)dis++;
		else s=min(s,v1[i].first-1);
	}
	cout<<s<<endl;
}