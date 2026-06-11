#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	cin.tie(0);
  	ios::sync_with_stdio(false);
  	int x, y;
  	int large;
  	cin >> x >> y;
  	
  	large = x > y?x:y;
  	
  	if(large <= 8)
  		cout << "Yay!" << endl;
  	else
      	cout << ":(" << endl;
	return 0;
}