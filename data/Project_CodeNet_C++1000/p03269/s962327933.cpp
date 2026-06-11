#include<bits/stdc++.h>
using namespace std;
int l,ll,k,bit,c;
int main(){
    scanf("%d", &l);
    ll=l;
	while(ll){
		k++;
		ll/=2;
	}
    bit=__builtin_popcount(l) - 1;
    printf("%d %d\n",k,2*(k-1)+bit);
    c=1<<(k-1);
    for(int i=k-2;i>=0;i--){
        printf("%d %d %d\n",i+1,i+2,1<<i);
        printf("%d %d %d\n",i+1,i+2,0);
        if((1<<i)&l){
            printf("%d %d %d\n",i+1,k,c);
            c+=1<<i;
        }
    }
}