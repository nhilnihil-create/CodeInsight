#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

int main(void){

    long long A,B;
    int K;
    cin >> A >> B >> K;
    
    int cont = 0;
    while(true){
        
        if(A%2==1)A--;
        B += A/2;
        A = A/2;
        cont++;
        if(cont == K)break;

        if(B%2==1)B--;
        A += B/2;
        B = B/2;
        cont++;
        if(cont == K)break;        
    
    }
    
    cout << A <<" "<<B<<endl;
}
