#include <bits/stdc++.h>
using namespace std;
 
int t,a,b;
int main(){
	cin >> t>>a>>b;
  	cout<<(t*a >= b ? b: t*a)<<endl;
}