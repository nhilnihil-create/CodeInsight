#include<iostream>
#include<math.h>
using namespace std;
int check(int a[100][3],int N,int x,int y){
	int b[100],d[100],j=0;
	for(int i=0;i<N;i++){
		b[i]=a[i][2]+fabs(double(a[i][0]-x))+fabs(double(a[i][1]-y));
	}
	int q=0;
	for(int k=0;k<N;k++){
		if(a[k][2]>0){
			q=b[k];
		}
	}
	for(int p=0;p<N;p++){
		if(a[p][2]==0){
			if(b[p]<q)
				return 0;
		}
		else{
			if(b[p]!=q)
				return 0;
		}
	}
	return q;
}
int main(){
	int N;
	cin>>N;
	int a[100][3];
	for(int i=0;i<N;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int x=0;x<=100;x++)
		for(int y=0;y<=100;y++){
			int f=check(a,N,x,y);
			if(f!=0){
				cout<<x<<" "<<y<<" "<<f<<endl;
				return 0;
			}
		}
	return 0;
}