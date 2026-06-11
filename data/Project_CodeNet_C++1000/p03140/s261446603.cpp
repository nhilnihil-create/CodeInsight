#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 

  int n;
  cin>>n;

  vector<char> a(n);
  vector<char>b(n);
  vector<char>c(n);
  
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }

  for(int i=0;i<n;i++){
    cin>>b.at(i);
  }

  for(int i=0;i<n;i++){
    cin>>c.at(i);
  }

  int cnt=0;
  for(int i=0;i<n;i++){
    if(a.at(i)==b.at(i)&&a.at(i)==c.at(i))
      cnt=cnt;
    else if(a.at(i)==b.at(i))
      cnt++;
    else if(b.at(i)==c.at(i))
      cnt++;
    else if(c.at(i)==a.at(i))
      cnt++;
    else
      cnt+=2;
  }

  cout<<cnt<<endl;

	return 0;
}