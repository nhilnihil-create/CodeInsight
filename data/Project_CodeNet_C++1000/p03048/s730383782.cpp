#include <bits/stdc++.h>
using namespace std;
int main(){
  int R,G,B,N; cin>>R>>G>>B>>N;
  int ans=0;
  for(int i=0;;i++){
    int count=N;
    if(count<R*i)break;
    count-=R*i;
    for(int j=0;;j++){
      int coun=count;
      if(count<G*j)break;
      coun-=G*j;
      if(coun%B==0)ans++;
    }
  }
  cout<<ans<<endl;
}