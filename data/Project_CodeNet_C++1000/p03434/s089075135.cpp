#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  
  int a[N];
  for( int i=0 ; i < N ; i++ ){
    cin >> a[i];
    }
  int w;
  for( int i=0 ; i<N-1 ; i++ ){
    for( int j=i+1 ; j<N ; j++ ){
      if( a[i] < a[j] ){
        w = a[i];
        a[i] = a[j];
        a[j] = w;
      }
    }
  }
  int h = 0, l = 0;
  for( int i=0 ; i<N ; i++ ){
    if( i%2 == 0 ){
    	h = h + a[i];
    }
    else{
    	l = l + a[i];
    }
  }
  cout << h-l << endl;
}