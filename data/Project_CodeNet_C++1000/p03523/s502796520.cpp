#include <bits/stdc++.h>
using namespace std;
string s[51]={ "KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA"};
string x;
int main(){
	cin>>x;
	for (int i=0;i<50;i++) if (s[i]==x){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	cout<<endl;
	return 0;
}