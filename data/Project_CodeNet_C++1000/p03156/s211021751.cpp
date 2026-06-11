#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,a,b;
	cin >>n>>a>>b;
	int x=0,y=0,z=0;
	for(int i=0;i<n;i++){
		int temp;
		cin >>temp;
		if(temp<a+1){
			x++;
		}else if(temp>b){
			z++;
		}else{
			y++;
		}
	}
	cout <<min(min(x,y),z)<<endl;
	
	return 0;
}