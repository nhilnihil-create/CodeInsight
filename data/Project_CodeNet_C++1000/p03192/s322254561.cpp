#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	int s=0;
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]=='2'){
			s++;
		}
	}
	cout<<s;
    return 0;
}