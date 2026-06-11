#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, c=1, t=0;
    cin >> A >> B;
    while(c<=3){
        if(A*B*c%2!=0){
            t=1;
            break;
        }
        c++;
    }
    if (t==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    

    return 0;
}