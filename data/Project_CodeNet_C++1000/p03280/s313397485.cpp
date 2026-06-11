#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	int A, B;

	cin >> A >> B;
	int s = A*B - A - B + 1;
	printf("%d\n", s);
	return 0;

}