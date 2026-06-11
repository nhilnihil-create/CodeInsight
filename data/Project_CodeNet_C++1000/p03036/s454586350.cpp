#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int r,d,x;
  	cin>>r>>d>>x;
  
  vector<int> A(110);
  A[0]=r*x-d;
  cout<<r*x-d<<endl;
  
  for(int i=1;i<10;i++){
  		cout<<r*A[i-1]-d<<endl;
    	A[i]=r*A[i-1]-d;
    	}
}