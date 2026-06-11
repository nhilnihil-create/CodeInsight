#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int64_t a = 2;
  	int64_t b = 1;
  	int64_t c,N;
  	cin >> N;
   	if(N == 1){
    cout << b << endl;
    }
  	if(N > 1){
  		for(int i = 1;i < N; i++){
			c = b + a;
    		a = b;
    		b = c;
    	}
      cout << c << endl;
    }
}