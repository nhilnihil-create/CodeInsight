#include <iostream>

using namespace std;

int main(){
int r,K;
int x;
scanf("%d%d%d",&r,&K,&x);
for(int i=0;i<10;i++){
x=x*r-K;
printf("%d\n",x);

}
}

