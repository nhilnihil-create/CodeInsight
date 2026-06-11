#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;

	for(int i; i < a+b+1; i++){
    	if(i == a){
        	if(s.at(i) != '-'){
              cout << "No" << endl;
          	  return 0;
            }
        }
        else{
            if(s.at(i) >= '0' && s.at(i) <= '9')
              continue;
            else{
              cout << "No" << endl;
              return 0;
            }
        }        
    }
  cout << "Yes" << endl;
  return 0;
}
