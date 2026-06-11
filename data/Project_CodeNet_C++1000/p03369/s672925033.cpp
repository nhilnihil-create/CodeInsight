#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n;
	n=0;
	for(int i=0; i<3;i++){
		if(s[i]=='o'){
			n++;
		}
	}
	cout<<700+100*n<<endl;
    return 0;
}