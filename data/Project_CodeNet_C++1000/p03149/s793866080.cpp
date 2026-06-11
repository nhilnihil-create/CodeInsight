// A - Beginning
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
int in(){int x;cin>>x;return x;}

int flag[10];

int main(){
	rp(i, 0, 4) flag[in()] = 1;
	int Y[] = {1,9,7,4};
	for(int y:Y) if(flag[y] != 1){ puts("NO"); return 0; }
	puts("YES");
}