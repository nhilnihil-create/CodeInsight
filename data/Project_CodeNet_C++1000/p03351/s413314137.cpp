#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int key;
  cin >> key;
  int flag;
  if(a-c >= 0 && a-c <= key)
    cout << "Yes" << endl;
  else if(c-a > 0 && c-a<= key)
    cout << "Yes" << endl;
  else if(a-b <= key && a-b >=-1*key && b-c <= key && b-c >= -1*key)
      cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
}
