#include <iostream>
using namespace std;

int main()
{
	char zero = '0';
	char ABCD[5];
	int a, b, c, d;
	int iSign[24] = {1,1,1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1};
	char cSign[24] = {'+','+','+','+','-','+','+','-','-','+','+','-','-','+','+','-','-','+','-','-','-','-','+','-'};
	int* pi = iSign;
	char* pc = cSign;

	cin >> ABCD;
	a = ABCD[0] - zero;
	b = ABCD[1] - zero;
	c = ABCD[2] - zero;
	d = ABCD[3] - zero;

	for (int i=0;i<24;i+=3) {
		if (a+b*(*(pi+i))+c*(*(pi+i+1))+d*(*(pi+i+2))==7) {
			cout << ABCD[0] << *(pc+i) << ABCD[1] << *(pc + i + 1) <<ABCD[2] << *(pc + i + 2) << ABCD[3] << "=7";
			return 0;
		}
	}
}