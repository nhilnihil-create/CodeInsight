#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;


int main()
{
	string str;
	cin>>str;
	if( str[0] != 'A'){
		cout<<"WA"<<endl;
		return 0;
	}
	int count = 0;
	for(int i = 2; i <= str.length() -2;i++){
		if(str[i] == 'C') count++;
	}
	if(count != 1){
		cout<<"WA"<<endl;
		return 0;
	}
	for(int i = 1; i < str.length(); i++){
		int num = str[i];
		if( (num < 'a'  || 'z' < num ) && (num != 'C')){
			cout<<"WA"<<endl;
			return 0;
		}
	}
	cout<<"AC"<<endl;
	return 0;
}
