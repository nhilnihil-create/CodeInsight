#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
    bool flag = false;
  cin >> a >> b;
  
  for(int i = 1; i <= 3; i++){
  	if(a * b * i % 2){
  		cout << "Yes" << endl;
      flag = true;
      break;
   	}
	}
  if(flag == false){
  	cout << "No" << endl;
  }
}