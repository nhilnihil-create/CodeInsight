#include<bits/stdc++.h>
#include<iomanip>

#define ll long long
#define ar array
 
using namespace std;



int main() {
	
	int a,b,c,d,e,f,maior,menor;
	
	cin >> a >> b >> c >> d >> e >> f;
	
	maior = e-a;
	
	if(maior > f){
		cout << ":(" <<endl;
	}else{
		cout << "Yay!" <<endl;
	}
	
	
   	return 0;
}