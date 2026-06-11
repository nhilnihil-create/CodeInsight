#include <iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<=N/4;i++){
        if((N-4*i)%7==0) {printf("Yes"); return 0;}
    }
    printf("No");
    return 0;
}