#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[10][10];
int main(){
	for(int i = 1; i <= 3; ++i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= 3; ++i) printf("%c", s[i][i]);
	return 0;
}