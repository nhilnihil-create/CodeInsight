#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int N, A, B;
	cin >> N >> A >> B;
	if (abs(A - B) % 2 == 0) cout << "Alice";
	else  cout << "Borys";
}