#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	string s;
	cin >> s;
	int n=s.size();
	
	if(s[n-7]=='k' && s[n-6]=='e' && s[n-5]=='y' && s[n-4]=='e' && s[n-3]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[n-6]=='e' && s[n-5]=='y' && s[n-4]=='e' && s[n-3]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	if(s[0]=='k' && s[1]=='e' && s[n-5]=='y' && s[n-4]=='e' && s[n-3]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[1]=='e' && s[2]=='y' && s[n-4]=='e' && s[n-3]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[1]=='e' && s[2]=='y' && s[3]=='e' && s[n-3]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[1]=='e' && s[2]=='y' && s[3]=='e' && s[4]=='n' && s[n-2]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[1]=='e' && s[2]=='y' && s[3]=='e' && s[4]=='n' && s[5]=='c' && s[n-1]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	if(s[0]=='k' && s[1]=='e' && s[2]=='y' && s[3]=='e' && s[4]=='n' && s[5]=='c' && s[6]=='e'){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	
	return 0;
}