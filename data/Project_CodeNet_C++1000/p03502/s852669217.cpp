#include <iostream>
using namespace std;

int main(){
  	int N, sum = 0;
  	cin >> N;
  	int tmp = N;
  	while(1){
      	sum += tmp%10;
      	if(tmp/10 == 0) break;
      	else tmp/=10;
    }
  	if(N%sum==0) cout << "Yes" << endl;
  	else cout << "No" << endl;
}