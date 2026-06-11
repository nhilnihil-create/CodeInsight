#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int N=262144;
struct Node{int x,y;}a[N];
Node merge(Node x,Node y){
	if(x.x<y.x)std::swap(x,y);
	Node answer=x;answer.y=std::max(answer.y,y.x);
	return answer;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin>>n;
	int p=1<<n;
	rep(i,0,p-1){
		int x;
		std::cin>>x;
		a[i]={x,-0x7f7f7f7f};
	}
	rep(j,0,n-1)rep(i,0,p-1)if(i>>j&1)a[i]=merge(a[i],a[i^(1<<j)]);
	int answer=a[0].x+a[0].y;
	rep(k,1,p-1){
		answer=std::max(answer,a[k].x+a[k].y);
		std::cout<<answer<<'\n';
	}
	return 0;
}