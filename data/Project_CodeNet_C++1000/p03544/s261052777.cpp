#include <iostream>

using namespace std;

long long int answers[87];

long long int lucas(int n){
  if (answers[n] != -1) return answers[n];
  long long int temp = lucas(n-1) + lucas(n-2);
  answers[n] = temp;
  return temp;
}

int main(){
  	memset(answers, -1, sizeof answers);
	answers[0] = 2;
	answers[1] = 1;
    int n;
    cin >> n;
    
    cout << lucas(n) << endl;
    return 0;
}