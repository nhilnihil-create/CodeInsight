#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b){
		if(a>c&&b<c){
			cout<<"Yes"<<endl;
			return 0;
			}
		}
	else if(a<b){
		if(a<c&&b>c){
			cout<<"Yes"<<endl;
			return 0;
			}
		}
	cout<<"No"<<endl;
	return 0;
}
