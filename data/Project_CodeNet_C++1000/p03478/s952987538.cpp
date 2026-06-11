#include <iostream>

using namespace std;

int f(int n){
    int sum = 0;
    while(n > 0){
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}

int main(){
    int n = 0;
    int N,A,B;
    cin >>N>>A>>B;
    for(int i = 1; i < N+1; ++i){
        if(A<=f(i) && f(i)<=B) n = n + i;
    }
    cout << n <<endl;
}