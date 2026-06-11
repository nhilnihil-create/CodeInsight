#include<bits/stdc++.h>

using namespace std;

int main(void){
    int A,B,C;
    cin>>A>>B>>C;
    int result=A*C;
    if(B>=result) cout<<C<<endl;
    else cout<<B/A<<endl;
    return 0;
}
