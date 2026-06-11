#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    if(A<=B && B/A >= C){
    cout<< C <<endl;
    }else if (A<=B && B/A < C){
        cout<< B/A <<endl;
    }else if (A > B){
        cout<< 0 <<endl;
    }
}