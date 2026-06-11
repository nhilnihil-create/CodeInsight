#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,t0,t1,t2,t3;
  cin >> N;

  t0=N/1000;
  t1=(N-1000*t0)/100;
  t2=(N-1000*t0-100*t1)/10;
  t3=(N-1000*t0-100*t1-10*t2);
    
  
  
  if (t1==t0){
    if(t2 == t1){
      cout << "Yes" << endl;
    }
    else{
      cout<< "No" << endl;
    }
  }
  else{
  	if(t1==t2){
    	if(t2==t3){
        	cout << "Yes" << endl;
        }
      	else{
        	cout << "No" << endl;
        }
    }
    else{
    	cout << "No" << endl;
    }
  }
}