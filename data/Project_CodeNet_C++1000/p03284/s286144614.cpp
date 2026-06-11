#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

  	if(N%K){
      cout << 1;
}
  else{
    cout << 0;
}
}
