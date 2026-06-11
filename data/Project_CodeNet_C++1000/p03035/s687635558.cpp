#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	int a,b,cost;
	cin >> a >> b;
	if(a >= 13){
		cost = b;
	}
	else if(a >= 6 && a <= 12){
		cost = b/2;
	}
	else
		cost = 0;
	cout << cost;
	
	
}	
