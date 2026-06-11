#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	char kata[5][5];
	
	for (int a=0;a<3;a++){
		scanf ("%s",kata[a]);
		getchar();
	}	
	
	printf ("%c%c%c\n",kata[0][0],kata[1][1],kata[2][2]);
}
