#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C; cin>>A>>B>>C;
    if(A==B){
        cout<<C;
        return 0;
    }
    else if(C==B){
        cout<<A;
        return 0;
    }
    else{
        cout<<B;
        return 0;
    }
    return 0;
}