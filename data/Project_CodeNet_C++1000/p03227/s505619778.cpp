#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  cin >> N;
  if(N.length() == 2){
  	cout << N << endl;
  }else{
  	for(int i = 0; i < N.length(); i++){
    	cout << N.at(2-i);
    }
    cout << endl;
  }
}