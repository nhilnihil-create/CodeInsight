#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A;
    cin>> N >> A;

    if (N<=10000 && N>=1 && A<=1000 && A>=0 && N%500<=A) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
        
        
    
    
