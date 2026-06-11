#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
 

int main() {
  int Q;
  cin>>Q;
  
  vector<int>l(Q);
  rep(i,Q) {    
    cin >> l.at(i);  
  }
  int to=abs(l.at(0))+abs(l.at(Q-1));
  rep2(i,1,Q){
    to+=abs(l.at(i)-l.at(i-1));
  }
  cout<<to+abs(l.at(1)-0)-(abs(l.at(1)-l.at(0))+abs(l.at(0)-0))<<endl;
  rep2(i,1,Q-1) {    
    cout<<to+abs(l.at(i+1)-l.at(i-1))-(abs(l.at(i+1)-l.at(i))+abs(l.at(i)-l.at(i-1)))<<endl;
  }
  cout<<to+abs(l.at(Q-2)-0)-(abs(l.at(Q-2)-l.at(Q-1))+abs(l.at(Q-1)-0))<<endl;
}