#include <iostream>

using namespace std;

int main(){
	char* num = (char*)calloc(5, sizeof(char));
	cin >> num;
	int a = num[0] - 48, b = num[1] - 48, c = num[2] - 48, d = num[3] - 48;
	
	if(a + b + c + d == 7) printf("%d+%d+%d+%d=7", a, b, c, d);
	else if(a + b + c - d == 7) printf("%d+%d+%d-%d=7", a, b, c, d);
	else if(a + b - c - d == 7) printf("%d+%d-%d-%d=7", a, b, c, d);
	else if(a - b - c - d == 7) printf("%d-%d-%d-%d=7", a, b, c, d);
	else if(a + b - c + d == 7) printf("%d+%d-%d+%d=7", a, b, c, d);
	else if(a - b - c + d == 7) printf("%d-%d-%d+%d=7", a, b, c, d);
	else if(a - b + c + d == 7) printf("%d-%d+%d+%d=7", a, b, c, d);
	else if(a - b + c - d == 7) printf("%d-%d+%d-%d=7", a, b, c, d);
}
