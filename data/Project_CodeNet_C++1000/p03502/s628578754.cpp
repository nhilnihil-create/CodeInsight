#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a=100000000,h=0;
  int count = 0;
  cin >> n;
  int n_new = n;
  
  while(count<9){
    h += n_new/a;
    n_new -= (n_new/a)*a;
    a /= 10;
    count ++;
  }
  
  if(h == 0){
    cout << "No" << endl;
  }else{
    int check=0;
    check = n % h;
  	if(check == 0){
    	cout << "Yes" <<endl;
  	}else{
    	cout << "No" << endl;
  	}
  }
}