#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	long long int a,b,ans=0;
	cin>>a>>b;
	for(int i=0;b>=a;i++){
		a=a*2;
		ans++;
	}
	cout<<ans<<endl;
	
	return 0;
	
}