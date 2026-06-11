#include <stdio.h>

int main() {
  int a, b;
  char string[20];
  bool valid = true;
  
  scanf("%d %d", &a, &b);
  scanf("%s",string);
  
  if(string[a] != '-'){
  	valid = false;
  }
  
	for(int i=0;string[i] != '\0'; i++){
		if(i != a){
			if(string[i] < '0' || string[i] > '9'){
				valid = false;
				break;
			}
		}
	}
	
	(valid) ? puts("Yes") : puts("No");
	
  return 0;
}