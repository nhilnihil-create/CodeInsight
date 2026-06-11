#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	string s;
	cin>>s;
	int w;
	cin>>w;
	char c[s.length()];
	strcpy(c,s.c_str());
	for(int j=0;j<s.length();j=j+w){
	    cout<<c[j];
	}
}