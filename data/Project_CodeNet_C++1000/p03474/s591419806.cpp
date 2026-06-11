#include <bits/stdc++.h>
#define pai 3.14159265
using namespace std;

int main(void){
    int A,B;
    string S;
    cin>>A>>B>>S;
    for(int i=0;i<A;i++){
        if(S[i]-'0'>9||S[i]-'0'<0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(S[A]!='-'){
        cout<<"No"<<endl;
        return 0;        
    }
    for(int i=A+1;i<A+B+1;i++){
        if(S[i]-'0'>9||S[i]-'0'<0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}