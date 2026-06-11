#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
  int N,A,B,a=0,b=0,c=0;
  cin>>N>>A>>B;
  int P[N];
  for(int i=0;i<N;i++){
    cin>>P[i];
    if(P[i]<=A) a++;
    else if(P[i]>B) c++;
    else b++;
  }
  cout<<min(a,min(b,c))<<endl;
}