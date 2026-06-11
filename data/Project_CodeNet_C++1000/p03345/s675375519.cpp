#include <bits/stdc++.h>
using namespace std;

#define UNFAIR 1000000000000000000

int main(){
    long long A,B,C,K;
    cin >> A >> B >> C >> K;

    if(K % 2 == 0){
        if(A - B > UNFAIR)
            cout << "unfair" << endl;
        else 
            cout << A - B << endl;
    }else{
        if(B - A > UNFAIR)
            cout << "unfair" << endl;
        else
            cout << B - A << endl;
    }

}