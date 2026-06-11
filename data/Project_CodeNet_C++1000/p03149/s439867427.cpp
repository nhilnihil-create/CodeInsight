#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector <int> n;
	int t;
	for(int i=0;i<4;i++){
		cin>>t;
		n.push_back(t);
	}
	sort(n.begin(),n.end());
	if(n[0]==1&&n[1]==4&&n[2]==7&&n[3]==9){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}