
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
//#include <cmath>
//#include <cstdlib>
using namespace std;


int main(){
	/*input*/
	int a,b,k;
	cin >> a >> b >> k;

	/*calc*/
    for(int i = 1; i <= k; i++){
    	if(i % 2 != 0){
    		if(a % 2 != 0){
    			a -= 1;
    			b += a/2;
    			a /= 2;
    		}
    		else{
    			b += a/2;
    			a /= 2;
    		}
    	}
    	else{
    		if(b % 2 != 0){
    			b -= 1;
    			a += b/2;
    			b /= 2;
    		}
    		else{
    			a += b/2;
    			b /= 2;
    		}
    	}
    }

    /*output*/
	cout<< a <<" "<< b <<endl;
    return 0;
}
