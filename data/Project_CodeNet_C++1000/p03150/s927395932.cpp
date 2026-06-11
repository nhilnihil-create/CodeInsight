#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  string s;
  cin>>s;
  int n=s.size();
  if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(2)=='y'&&s.at(3)=='e'&&s.at(4)=='n'&&s.at(5)=='c'&&s.at(6)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(2)=='y'&&s.at(3)=='e'&&s.at(4)=='n'&&s.at(5)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(2)=='y'&&s.at(3)=='e'&&s.at(4)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(2)=='y'&&s.at(3)=='e'&&s.at(n-3)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(2)=='y'&&s.at(n-4)=='e'&&s.at(n-3)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(1)=='e'&&s.at(n-5)=='y'&&s.at(n-4)=='e'&&s.at(n-3)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(0)=='k'&&s.at(n-6)=='e'&&s.at(n-5)=='y'&&s.at(n-4)=='e'&&s.at(n-3)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else if(s.at(n-7)=='k'&&s.at(n-6)=='e'&&s.at(n-5)=='y'&&s.at(n-4)=='e'&&s.at(n-3)=='n'&&s.at(n-2)=='c'&&s.at(n-1)=='e'){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}