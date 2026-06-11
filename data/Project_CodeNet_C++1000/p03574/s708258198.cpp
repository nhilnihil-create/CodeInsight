#include<bits/stdc++.h>
using namespace std;

int main(void){
  int h, w;
  cin >> h >> w;
  
  char k[h*w];
  for( int i=0 ; i<h*w ; i++ ){
    cin >> k[i];
  }

  int l[h*w];
  for( int i=0 ; i<h*w ; i++ ){
    l[i] = 0;
  }
  
  for( int i=0 ; i<h*w ; i++ ){
    if( k[i] == '#' ){
      if( i-w-1 >= 0 && i%w != 0 )  l[i-w-1]++;  //'#'の左上に+1
      if( i-w >= 0 )  l[i-w]++;  //'#'の上に+1
      if( i-w+1 >= 0 && i%w != w-1 ) l[i-w+1]++;  //'#'の右上に+1
      if( i-1 >= 0 && i%w != 0 )  l[i-1]++;  //'#'の左に+1
      if( i%w != w-1) l[i+1]++;  //'#'の右に+1
      if( i+w-1 < h*w && i%w != 0 )  l[i+w-1]++;  //'#'の左下に+1
      if( i+w < h*w )  l[i+w]++;  //'#'の下に+1
      if( i+w+1 < h*w && i%w != w-1 ) l[i+w+1]++;  //'#'の右下に+1
    }
  }
// for( int i=0 ; i<h*w ; i++ )  cout << l[i] << endl;
  for( int i=0 ; i<h*w ; i++ ){
    if( k[i] != '#' )  cout << l[i];
    else cout << k[i];
    if( i%w == w-1 ){
      cout << endl;
    }
  }
}