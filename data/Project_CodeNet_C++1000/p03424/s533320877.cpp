#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt ;
  cin >> cnt;
  
  int g,w,p,y;
  g=0;w=0;p=0;y=0;
  
  string c ;
  
  for (int i =0; i< cnt ; i++ ){
  	cin >> c;
    if (c=="G"){
      g=1;
    }
    else if (c=="W"){
      w=1;
    }
    else if (c=="P"){
      p=1;
    }
    else if (c=="Y"){
      y=1;
    }
  }
  
  int ccnt = g+w+p+y;
  if (ccnt==3) {
  	cout << "Three";
  }
  else if (ccnt == 4){
    cout << "Four";
  }
  
}
