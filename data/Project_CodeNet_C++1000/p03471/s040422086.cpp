#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()

int main() {
  int N,Y;
  int d=-1;
  int e=-1;
  int f=-1;
 cin>>N>>Y;
  for(int a=0;a<=N;a++){
    for(int b=0;b<=N;b++){
      int c=N-a-b;
    if(Y==10000*a+5000*b+1000*c&&c>=0){
    d=a;
    e=b;
    f=c;
    }
   }
  }
  cout<<d<<" "<<e<<" "<<f<<endl;
}
