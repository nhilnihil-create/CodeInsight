#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    while(cin >> a >> b) {
        if(a * b == 15) {
            printf("*\n");
//            printf("%d×%d=15.\n",a,b);
        } else if(a + b == 15) { 
            printf("+\n");
//            printf("%d+%d=15.\n",a,b);
        } else {
            printf("x\n");
//            printf("%d+%d=%d and %d×%d=%d, neither of which is 15.\n",
//                   a,b,a + b,a ,b,a * b);
        }
    }
    return 0;
}
