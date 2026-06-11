#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	int a,b,x;
	string s="NO";
	cin>>a>>b>>x;
	if(b>=x-a&&x-a>=0){
		s="YES";
	}
	cout<<s<<endl;
    return 0;
}