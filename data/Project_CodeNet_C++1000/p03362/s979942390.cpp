#include <iostream>
#include <vector>
using namespace std;
template <typename T>
bool isPrime(T n){
  
  for(T i = 2; n >= i*i; i++){
    if(!(n%i)){return false;}
  }
  return true;
}
int main(){
	int n;cin>>n;
	vector<int> A;
	for(int i = 11; 55555 > i && A.size() != n; i+=10){
		if(isPrime(i))A.push_back(i);
	}
	for(int i = 0; n > i; i++){
		cout << A[i];
		if(i+1 != n)cout << " ";
	}
	cout << endl;
}