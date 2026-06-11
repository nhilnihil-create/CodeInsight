#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char str[100003]; int N;

int main(){
	scanf("%s" , str + 1); N = strlen(str + 1);
	if(str[1] == '0' || str[N] == '1'){puts("-1"); return 0;}
	for(int i = 1 ; i < N ; ++i) if(str[i] != str[N - i]){puts("-1"); return 0;}
	int pre = 1;
	for(int i = 2 ; 2 * i <= N ; ++i){
		if(str[i] == '1') while(pre < i) cout << pre++ << ' ' << i << endl;
	}
	while(pre < N) cout << pre++ << ' ' << N << endl;
    return 0;
}