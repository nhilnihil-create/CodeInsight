#include <bits/stdc++.h>
using namespace std;

bool is_integer( double x ){
  return floor(x)==x;
}

int main(void){
   
    int N;
    cin >> N;

    for(int i=N;i>=1;i--){
        if(is_integer(sqrt(i))){
            cout << i << endl;
            return 0;
        }
    }
   
}