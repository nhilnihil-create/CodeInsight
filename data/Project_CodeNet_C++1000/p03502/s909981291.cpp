// B - Harshad Number
#include <bits/stdc++.h>
using namespace std;

int f(string x){
	int ret = 0;
	for(auto &c:x) ret += c - '0';
	return ret;
}

int main(){
	string x; cin>>x;
	cout<< (stoi(x) % f(x)? "No":"Yes") <<endl;
}
