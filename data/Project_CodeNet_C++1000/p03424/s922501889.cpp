#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  char color[N];
  for(int i=0; i<N; i++){
    cin >> color[i];
  }
  
  int  p=0,w=0,g=0,y=0;
  for(int i=0; i<N; i++){
    if( color[i] == 'P' ){p = 1;}
    else if( color[i] == 'W' ){w = 1;}
    else if( color[i] == 'G' ){g = 1;}
    else if( color[i] == 'Y' ){y = 1;}
  }
  if(p+w+g+y == 3){cout<< "Three" << endl;}
  if(p+w+g+y == 4){cout << "Four" << endl;}
  
  return 0;
}
