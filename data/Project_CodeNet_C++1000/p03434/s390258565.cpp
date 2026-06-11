#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a;
  cin>>N;
  vector <int> s(0);
  for (int i=0;i<N;i++){
    cin>>a;
    s.push_back(a);
  }
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  int p,q;
  p=0;
  q=0;
  for (int i =0;i<N;i++){
    if (i % 2==0){
      p+=s.at(i);
    }
    else{
      q += s.at(i);
    }
  }
  cout << p-q << endl;    
  
}
