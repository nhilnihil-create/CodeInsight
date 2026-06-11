#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int d;
	cin >> d;
	char* ans = (char*)calloc(100, sizeof(char));
	switch(d){
	case 22:
		strcpy(ans, "Christmas Eve Eve Eve");
		break;
	case 23:
		strcpy(ans, "Christmas Eve Eve");
		break;
	case 24:
		strcpy(ans, "Christmas Eve");
		break;
	case 25:
		strcpy(ans, "Christmas");
		break;
	}
	cout << ans;
}