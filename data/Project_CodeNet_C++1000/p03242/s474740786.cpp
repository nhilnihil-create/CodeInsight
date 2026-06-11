#include <bits/stdc++.h>

int main (){
	int i;
	char str[10];
	scanf("%s", str);
	for(i = 0; i < 3; ++i){
		if(str[i] == '1' || str[i] == '9')
			str[i] = '1' + '9' - str[i];
	}
	puts(str);
	return 0;
}
