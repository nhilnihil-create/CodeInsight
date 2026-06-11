#include<bits/stdc++.h>
using namespace std;
int main() {
    
	int n , k , total=1 ;
	
	cin >> n >> k ;
	
	while(n--)
	{
	    if(total*2>(total+k)) total+=k;
	    else total<<=1 ;
	}
	
	cout<<total;
}