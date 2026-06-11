#include <bits/stdc++.h>
using namespace std;

int main(){
  char a,b;
  cin >> a >> b;
  if(int(a)<int(b)){
    cout << "<" << endl;
  }
  else if(int(a)==int(b)){
    cout << "=" << endl;
  }
  else{
    cout << ">" << endl;
  }
}
