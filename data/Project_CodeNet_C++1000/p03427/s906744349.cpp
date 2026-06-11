#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	string N;
	cin >> N;
	char prop_c[N.length()+1];
	for(int i=0;i<N.length();i++){
		prop_c[i]='9';
	}
	prop_c[N.length()]=0;
	string prop(prop_c);


	prop[0]=N[0];
	if(N==prop){
		cout << ( (N.length()-1)*9+((N[0]-'0')) ) << endl;
	}else{
		cout << ( (N.length()-1)*9+((N[0]-'0')-1) ) << endl;
	}

	return 0;
}
