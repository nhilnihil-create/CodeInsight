#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	if(s.length()==3){
		reverse(s.begin(),s.end());
		cout<<s;
	}else cout<<s;
	return 0;
}