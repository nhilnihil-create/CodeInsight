#include<bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, l;
  	l = 0;
  	cin >> N;
  	for(int i = 0; i < 50; i++){
    	for(int j = 0; j < 50 && l == 0; j++){
        if(N == 4 * i + 7 * j){
        	l = 1;
        }
       }
    }
  if(l == 0)
  {cout << "No" << endl;}
  else{cout << "Yes" << endl;}
}