#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,K;
    cin >> A >> B >> K;
    for(int i=1;i<=K;i++){
        if(i%2==1){
            A/=2;
            B+=A;
        }
        else{
            B/=2;
            A+=B;
        }
    }
    cout << A << " " << B << endl;

}