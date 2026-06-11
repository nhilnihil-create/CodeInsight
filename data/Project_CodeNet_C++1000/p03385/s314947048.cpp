#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	string s, t="No";
	cin>>s;
	if(s[0]!=s[1]&&s[1]!=s[2]&&s[0]!=s[2]){
		t="Yes";
	}
	cout<<t<<endl;
    return 0;
}