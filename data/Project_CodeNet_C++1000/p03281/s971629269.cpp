#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
  	cin >> n;
  	int oddeight = 0;
  	for(int i=1;i<=n;i++){
    	int a=i;
      	if(a%2 == 1){
        	int cou=0;
          	for(int j=1;j<=a;j++){
            	if(a%j==0) cou++;              
            }
          	if(cou==8) oddeight++;
        }
    }
  	cout << oddeight << endl;
}