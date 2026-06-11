#include <cstdio>
using namespace std;

int main() {
	int S;
	scanf("%d", &S);
	
	int S1, S2;
	S1 = S / 100;
	S2 = S % 100;
	
	bool month1 = (1 <= S1 && S1 <= 12)? true : false;
	bool month2 = (1 <= S2 && S2 <= 12)? true : false;
	
	if(month1) {
		if(month2) printf("AMBIGUOUS");
		else printf("MMYY");
	} else {
		if(month2) printf("YYMM");
		else printf("NA");
	}
	
	return 0;
}