#include <iostream>

using namespace std;

int main(){
    int ab, bc, ca, area;
    scanf("%d %d %d", &ab, &bc, &ca);
    if(ab > bc && ab > ca){
        area = bc * ca / 2;
    }else if(bc > ab && bc > ca){
        area = ab * ca / 2;
    }else{
        area = ab * bc / 2;
    }
    printf("%d\n", area);
    return 0;
}