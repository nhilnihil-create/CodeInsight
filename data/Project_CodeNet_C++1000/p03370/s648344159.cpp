#include <iostream>
#include <algorithm>


using namespace std;
int main(void){
    int N,X;
    int m[101];
    cin>>N>>X;
    int rem=X;
    for(int i=0;i<N;i++){
        cin>>m[i];
        rem-=m[i];
    }
    sort(m,m+N);
    printf("%d",N+rem/m[0]);
    
}