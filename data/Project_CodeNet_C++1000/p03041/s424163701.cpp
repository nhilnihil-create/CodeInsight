#include <iostream>
#include <string>
using namespace std;

int n,k;
string s;

int main(){
	cin>>n>>k>>s;
	s[k-1]+=32;
	cout<<s<<endl;
}