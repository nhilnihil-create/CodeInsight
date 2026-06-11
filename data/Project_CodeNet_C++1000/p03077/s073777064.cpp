#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,A,B,C,D,E;
  cin>>N>>A>>B>>C>>D>>E;
  long long F=min({A,B,C,D,E});
  cout<<(N+F-1)/F+4<<endl;
}