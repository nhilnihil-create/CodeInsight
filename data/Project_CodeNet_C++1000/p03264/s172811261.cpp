#include<cstdio>
using namespace std;
int main(){
    #ifdef LOCAL
    freopen("a", "r", stdin);
    #endif // LOCAL
    int n;
    while(~scanf("%d", &n)){
        if(n&1){
            printf("%d\n", n/2*(n/2+1));
        }
        else{
            printf("%d\n", n/2*(n/2));
        }
    }
}
