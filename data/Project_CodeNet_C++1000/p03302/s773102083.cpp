#include <iostream>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
//const int MAX=;

int dsum(int n){
	if(n<10) return n;
	return dsum(n/10)+n%10;
}

int main(){
	int a,b;
	cin>>a>>b;
	if(a+b==15)cout<<"+";
	else if(a*b==15)cout<<"*";
	else cout<<"x";
}
