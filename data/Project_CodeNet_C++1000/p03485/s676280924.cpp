#include <iostream>
#include <string.h>
using namespace std;

void a_round_up_the_mean(void){
	int a, b;
	cin >> a >> b;
	int x = (a + b + 1) >> 1;
	cout << x << endl;
}

int main()
{
	a_round_up_the_mean();
    return 0;
}