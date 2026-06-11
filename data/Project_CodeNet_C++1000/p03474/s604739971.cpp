#include <stdio.h>
#include <string.h>

int main() {
	int a,b;
	char s[15];
	int counter = 0;
	
	scanf ("%d %d", &a, &b);
	scanf ("%s", &s);
	
	for (int i=0; s[i] != '\0'; i++){
        if (s[a] != '-') {
            printf ("No\n");
            return 0;
        }
        if (s[i] >= '0' && s[i] <= '9'){
            counter++;
        }
    }
    if (counter == a+b) {
        printf ("Yes\n");
    }
    else{
        printf ("No\n");
    }
    
    
	return 0;
}