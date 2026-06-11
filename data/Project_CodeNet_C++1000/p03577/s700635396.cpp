#include <iostream>
#include <vector>
using namespace std; using P=pair<int,int>; using ll=long long; template<class T> using vec=vector<T>;
int main() {
	string s; cin>>s;
	cout<<s.substr(0,s.size()-8)<<endl;
}