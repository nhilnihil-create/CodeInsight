#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,c,x=0,y=0,t=0,pos=1;
  	scanf("%d",&n);
    while(n--){
    	scanf("%d%d%d",&c,&a,&b);
        int step = abs(x-a) + abs(y-b);
        x = a, y = b;
        pos = pos && (c-t-step >= 0 && (c-t-step)%2 == 0);
    	t = c;
    }
    if(pos)printf("Yes");
    else printf("No\n");
    return 0;
}