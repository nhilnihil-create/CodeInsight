#include <iostream>
static const int INF=1<<20;
using namespace std;

int digitSum(int n){
    int res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}



int main(){
    int N;
    cin>>N;
    int Min=INF;
    for(int i=1;i<=N/2;i++){
        Min=min(digitSum(i)+digitSum(N-i),Min);
    }
    printf("%d",Min);
    return 0;
}

