#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,p[4];
  	cin >> n;
  	p[0]=n%10; n/=10;
  	p[1]=n%10; n/=10;
    p[2]=n%10; n/=10;
  	p[3]=n%10; n/=10;      
  	if(p[1]==p[2]){
      if(p[0]==p[1] || p[3]==p[1]){
 		   cout << "Yes" << endl;
      }
      else{
      	cout << "No" << endl;
      }
    }else{
    cout << "No" << endl;
    }
}