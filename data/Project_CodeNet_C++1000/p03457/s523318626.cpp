#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0;i<n;i++){
  	cin >> t[i] >> x[i] >> y[i];
  }
  bool flg=true;
  if(x[0]+y[0]>t[0]){flg=false;}
  if(x[0]+y[0]<=t[0]){
  	if((x[0]+y[0]-t[0])%2==1){flg=false;}
  }
  for(int i=1;i<n;i++){
  	int a=abs(x[i]-x[i-1]);
    int b=abs(y[i]-y[i-1]);
    int c=abs(t[i]-t[i-1]);
    if(a+b>c){
    	flg=false;
      break;
    }
    if(a+b<c){
    	if((c-a-b)%2==1){
        	flg=false;
          break;
        }
    }
  }
  if(flg){cout << "Yes" << endl;}
  else{cout << "No" << endl;}
}

