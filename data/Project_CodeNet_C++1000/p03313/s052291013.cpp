#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int x[1<<18];
int t[1<<18][2];

int wh_max(int a,int b){
	if(a==-1)return b;
	if(b==-1)return a;
	return x[a]>x[b]?a:b;
}

int wh_max(int a,int b,int c){
	return wh_max(wh_max(a,b),c);
}

int update(int a,int b){
	if(t[a][0]==t[b][0])t[a][1]=wh_max(t[a][1],t[b][1]);
	else if(x[t[a][0]]<x[t[b][0]])t[a][1]=wh_max(t[a][0],t[a][1],t[b][1]),t[a][0]=t[b][0];
	else t[a][1]=wh_max(t[a][1],t[b][0],t[b][1]);
}

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	int s=0;
	memset(t,-1,sizeof(t));
	cin>>n;
	for(i=0;i<(1<<n);i++){
		cin>>x[i];
		t[i][0]=i;
		for(j=0;j<n;j++){
			if(i&(1<<j))update(i,i-(1<<j));
		}
	}
	for(i=1;i<(1<<n);i++){
		s=max(s,x[t[i][0]]+x[t[i][1]]);
		if(i>0)cout<<s<<endl;
	}
	return 0;
}
