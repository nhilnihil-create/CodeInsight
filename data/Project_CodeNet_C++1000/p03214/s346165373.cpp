#include<iostream>
#include<vector>
using namespace std ;

double max(double a,double b){
	if(a>=b) return a ;
	else return b ;
}
double min(double a,double b){
	if(a<=b) return a ;
	else return b ;
}
double sa(double a,double b){
	return max(a,b)-min(a,b) ;
}

int main(){
	double n ; cin >> n ;
	vector<int> a(n) ;
	double sum = 0 ;
	for(int i=0;i<n;i++){
		cin >> a.at(i) ;
		sum += a.at(i) ;
	}
	double avr = sum/n ;
	int m = 0 ;
	double sm = 10000 ;
	for(int i=0;i<n;i++){
		if(a.at(i)==avr){
			cout << i << endl ;
			return 0 ;
		}
		if(sa(a.at(i),avr)<sm){
			sm = sa(a.at(i),avr) ;
			m = i ;
		}
	}
	cout << m << endl ;
}
