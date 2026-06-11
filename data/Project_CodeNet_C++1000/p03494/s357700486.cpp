#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a,counter,save;
  cin >> N;
  save = -1;
  for (int i=0;i<N;i++){
    cin >> a;
    counter=0;
    while(a%2==0){
      a/=2;
      counter+=1;
    }

  if (counter < save)
       save =counter;
else if(save==-1)
     save =counter;

  else 
      continue; 
  }
  cout << save << endl;
}
