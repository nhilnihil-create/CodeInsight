#include<iostream>
using namespace std;
int main(){
  int i,n,k;
  char s[100];
  cin >> n >> k;
  for(i=0;i<n;i++){
    cin >> s[i];
  }
  s[k-1]=tolower(s[k-1]);
  for(i=0;i<n;i++){
    cout << s[i];
  }
  cout << endl;
  return 0;
}