    #include <iostream>
    #include <array>
    using namespace std;
    int  A,B,x;

    int main() {
    scanf("%d", &A);
    scanf("%d", &B);

    x = A+B;
    if (A-B > x){
       x = A-B;
    }
    if (A*B > x) {
        x = A*B;
    }

    printf("%d",x);
    }
