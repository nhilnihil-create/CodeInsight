#include<iostream>
 
using namespace std;
 
int main(){
    char S[5];
    scanf("%s", S);
    int sum=0;
    for(int i=0; i<4; i++){
        if(S[i]=='-')sum--;
        else sum++;
    }
    printf("%d\n", sum);
    return 0;
}