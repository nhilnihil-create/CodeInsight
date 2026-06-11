#include<iostream>
#include<set>
using namespace std ;

int main(){
	int n ;
	set<int> a ;
	for(int i=0;i<4;i++){
		cin >> n ;
		a.insert(n) ;
	}
	if(a.count(1)&&a.count(9)&&a.count(7)&&a.count(4))
		cout << "YES" << endl ;
	else
		cout << "NO" << endl ;
}
