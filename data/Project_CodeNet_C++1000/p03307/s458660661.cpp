#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int N,e, cont;
	cin >> N;
	cont = N;
	e = 10;
	
	while(e != 0){
		if(cont % 2 == 0 && cont % N == 0){
			cout << cont << "\n";
			e = 0;
		}
		cont= cont + N;
	}
	return 0;
}
