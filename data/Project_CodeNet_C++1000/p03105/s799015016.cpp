#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,D;
    cin >> A >> B >> C;
    if (B-A*C >=0){
        cout << C << endl;

    }else{
        D = B/A;
        cout << D << endl;
    }
    
}
