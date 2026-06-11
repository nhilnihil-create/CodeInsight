#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int p1=A+C;
  int p2=A+D;
  int p3=B+C;
  int p4=B+D;
  int minimumplan=min(p1,min(p2,min(p3,p4)));
  
  cout<<minimumplan<<endl;
}
