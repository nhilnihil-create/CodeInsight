#include<bits/stdc++.h>
using namespace std;
struct Po{int x,y;}a[1010];
int f[5],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {scanf("%d %d",&a[i].x,&a[i].y);f[(((a[i].x+a[i].y)%2)+2)%2]++;}
	if (f[0]==0||f[0]==n){
		if (f[0]==n){
			cout<<"32"<<endl;cout<<"1 ";
			for (int i=30;i>=0;i--)cout<<(1<<i)<<' ';cout<<endl;
			for (int i=1,j;i<=n;i++){
				cout<<"U";a[i].y--;
				for (int j=30;j>=0;j--){
					if (abs(a[i].x)<abs(a[i].y)){
						if (a[i].y>0){cout<<"U";a[i].y-=(1<<j);}else{cout<<"D";a[i].y+=1<<j;}
					}else{
						if (a[i].x>0){cout<<"R";a[i].x-=(1<<j);}else{cout<<"L";a[i].x+=1<<j;}						
					}
				}
				cout<<endl;
			}
		}else{
			cout<<"31"<<endl;
			for (int i=30;i>=0;i--)cout<<(1<<i)<<' ';cout<<endl;
			for (int i=1,j;i<=n;i++){
				for (int j=30;j>=0;j--){
					if (abs(a[i].x)<abs(a[i].y)){
						if (a[i].y>0){cout<<"U";a[i].y-=(1<<j);}else{cout<<"D";a[i].y+=1<<j;}
					}else{
						if (a[i].x>0){cout<<"R";a[i].x-=(1<<j);}else{cout<<"L";a[i].x+=1<<j;}						
					}
				}
				cout<<endl;
			}
		}
	}else{
		cout<<"-1"<<endl;
	}	
	return 0;
}