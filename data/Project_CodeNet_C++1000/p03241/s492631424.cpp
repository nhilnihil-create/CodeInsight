#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m, lp, les;
	cin>> n >> m;

  	lp=(m+n-1)/n;
  	//cout<< lp <<endl;//
  
  	for(int i=lp;i>0;i--){
      les=m-n*i;
      //cout<< i << " " << les <<endl;//
      if(les%i==0){
        cout<< i <<endl;
        return 0;
      }
    }
 
	return 0;
}