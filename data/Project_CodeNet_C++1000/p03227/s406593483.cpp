/* Bismillahirrahmanirrahim */
#include<bits/stdc++.h>
#define forA for(int i=0; i<a; i++)
using namespace std;

int main(){
	string str;
	cin >> str;
	int size=str.size();
	if(size==2) cout << str;
	else{
		swap(str[0],str[2]);
			cout << str;
	}

}
