#include <iostream>
using namespace std;

int main(){
  	int N;
  	cin >> N;
  	int min_div = 30;
  	for (int i = 0; i < N; i++){
      	int x;
      	cin >> x;
      	int res = 0;
      	while (x%2==0){
          	x /= 2;
          	res++;
        }
      	min_div = res < min_div ? res : min_div;
    }
  	cout << min_div << endl;
}