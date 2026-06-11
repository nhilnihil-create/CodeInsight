#include<bits/stdc++.h>
using namespace std;

int f(int n){
  if(n%2==0)
    return n/2;
  return n*3+1;
}
int main(){
  int n;
  cin >> n;
  vector<int>hen(n);
  for(int i=0;i<n;i++)
    cin >> hen.at(i);
  sort(hen.begin(),hen.end(),greater());
  int a=0;
  for(int i=1;i<n;i++)
    a+=hen.at(i);
  cout << ((hen.at(0)<a)?"Yes":"No") << endl;
  return 0;
}