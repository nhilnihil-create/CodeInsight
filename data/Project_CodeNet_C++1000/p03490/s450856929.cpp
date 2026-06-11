#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8005, ZERO = 8000;

int p[2]; char str[MAXN];
bitset <MAXN << 1> bs[2];

int main(){
	int i, j, d;
	scanf("%s%d%d", str + 1, &p[0], &p[1]);
	for(i = 1; str[i] == 'F'; ++ i) -- p[0];
	if(p[0] < -ZERO){
		printf("No\n");
		return 0;
	} bs[0][ZERO] = bs[1][ZERO] = true;
	for(d = 0; str[i]; i = j){
		for(j = i; str[j] == 'F'; ++ j) ;
		bs[d] = (bs[d] << (j - i)) | (bs[d] >> (j - i));
		if(str[j] == 'T') ++ j, d ^= 1;
	} printf("%s\n", bs[0][p[0] + ZERO] && bs[1][p[1] + ZERO] ? "Yes" : "No");
	return 0;
}