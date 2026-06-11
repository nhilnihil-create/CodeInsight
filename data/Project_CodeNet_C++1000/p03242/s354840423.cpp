#include<cstdio>
using namespace std;
int upd(int x){
    if(x == 1){
        x = 9;
    }
    else if(x == 9){
        x = 1;
    }
    return x;
}
int main(){
    int n;
    while(~scanf("%d", &n)){
        int x = n/100, y = n%100/10, z = n%10;
        x = upd(x);
        y = upd(y);
        z = upd(z);
        printf("%d\n", x*100 + y*10 + z);
    }
}
