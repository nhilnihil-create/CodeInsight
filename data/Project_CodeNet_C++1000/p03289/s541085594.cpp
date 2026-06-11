#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;cin>>S;
    if(S[0]!='A'){
        cout<<"WA"<<endl;
        return 0;
    }
    int C=0;
    for(int i=0;i<S.size();i++){
        if(i>=2&&i<=S.size()-2){
            if(S[i]=='C'){
                C++;
            }
        }
        else if(i!=0){
            if(S[i]<97||S[i]>122){
                cout<<"WA"<<endl;
                return 0;
            }
        }
    }
    if(C>1||C<1){
        cout<<"WA"<<endl;
        return 0;
    }
    cout<<"AC"<<endl;
    return 0;
}