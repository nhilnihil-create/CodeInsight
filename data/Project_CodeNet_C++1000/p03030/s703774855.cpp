#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	int point;
	int id;
}b[101];
int cmp(node a,node b){
	if(a.s==b.s)
		return a.point>b.point;
	return a.s<b.s;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>b[i].s;
		cin>>b[i].point;
		b[i].id=i+1;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++)
		printf("%d\n",b[i].id);
}