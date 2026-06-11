#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;

int main(){
	int H,W,N;
	
	scanf("%d %d %d",&N,&H,&W);

	printf("%d\n",(N-W+1)*(N-H+1));
	
	return 0;
}
