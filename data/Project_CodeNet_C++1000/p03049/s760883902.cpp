#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;

int main(){
	int n ; cin >> n ;
	int a,b,ab,both ;
	a = b = ab = both = 0 ;
	for(int i=0;i<n;i++){
		string s ; cin >> s ;
		if(s.at(0)=='B') b++ ;
		if(s.at(s.size()-1)=='A') a++ ;
		if(s.at(0)=='B'&&s.at(s.size()-1)=='A') both++ ;
		for(int i=1;i<s.size();i++){
			if(s.at(i-1)=='A'&&s.at(i)=='B') ab++ ;
		}
	}
	if(a==b&&a==both&&both!=0) ab-- ;
	cout << ab+min(a,b) << endl ;
	//cout << ab << " " << a << " " << b ;
}