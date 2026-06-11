#include <iostream>
using namespace std;

int main(){
    int n, a, b;

    cin >> n >> a >> b;

    int maxn = min(a, b);
    int minv;

    if(a + b - n < 0){
        minv = 0;
    }
    else{
        minv = a + b - n;
    }

    printf("%d\n", maxn);
    printf("%d\n", minv);

    return 0;
}