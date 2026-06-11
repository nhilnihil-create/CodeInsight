#include <iostream>
#include <iomanip>
using namespace std; 

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t,x;cin>>t>>x;
  	cout<< setprecision(5) << (float) t/x;
}