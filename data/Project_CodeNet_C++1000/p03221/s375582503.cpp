#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int x,y,num;
}Edge[100005];
 
bool cmp(Node a,Node b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}
 
bool cmp1(Node a,Node b){
	return a.num < b.num;
}
 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&Edge[i].x,&Edge[i].y);
		Edge[i].num = i;
	}
	sort(Edge,Edge+m,cmp);
	int num = 1;
	for(int i=0;i<m-1;i++){
		if(Edge[i].x == Edge[i+1].x){
			Edge[i].y = num++;
		}
		else{
			Edge[i].y = num;
			num = 1;
		}
	}
	if(Edge[m-1].x == Edge[m-1].x) Edge[m-1].y = num;
	else Edge[m-1].y = ++num;
	sort(Edge,Edge+m,cmp1);
	for(int i=0;i<m;i++){
		printf("%06d%06d\n",Edge[i].x,Edge[i].y);
	}
	return 0;
}