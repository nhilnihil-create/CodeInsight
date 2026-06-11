#include <iostream>
using namespace std;

int Sum_each(int A){
  	int sum = 0, tmp = A;
  	while(1){
      	sum += tmp%10;
      	if(tmp/10 == 0) break;
      	else tmp = tmp/10;
    }
  	return sum;
}

int main(){
  	int N;
  	cin >> N;
  	int min = N;
  	for (int i = 1; i < N; i++){
      	int sum = Sum_each(i)+Sum_each(N-i);
      	if(sum < min) min = sum;
    }
  	cout << min << endl;
}