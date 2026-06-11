#include <bits/stdc++.h>



using namespace std;


int main (){
	int n, k;
	
	cin >> n >> k;
	int max = n/2 + (n%2!=0);
	
	if(k <= max){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}
















