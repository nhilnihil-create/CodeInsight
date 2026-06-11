#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ta=0,tb=0;
  cin >> n;
  int vec[n];
  for(int i=0;i<n;i++)
    cin >> vec[i];
  int max=vec[0],line[n];
  for(int t=0;t<n;t++){
    //maxを見つける
    for(int i=0;i<n;i++){
      if(max<vec[i])
        max=vec[i];
    }
    line[t]=max;
    //maxを取り除く
    for(int i=0;i<n;i++){
      if(max==vec[i]){
        vec[i]=0;
        break;
      }
    }
    max=0;
  }
  for(int i=0;i<n;i+=2)
    ta+=line[i];
  for(int i=1;i<n;i+=2)
    tb+=line[i];
  cout << ta-tb << endl;
}

   