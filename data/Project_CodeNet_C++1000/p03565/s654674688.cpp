#include<iostream>
#include<string>
using namespace std;

int main(){
    //input
    string S,T;
    cin >> S >> T;

    //calc
    int i,j;
    bool exist;
    for(i=S.length()-T.length(); i>=0; i--){
        exist=1;
        for(j=0; j<T.length(); j++){
            if(S[i+j]!='?'&&S[i+j]!=T[j]){
                exist=0;
            }
        }
        if(exist){
            break;
        }
    }
    //answer
    if(i>=0){
        for(j=0; j<i; j++){
            if(S[j]=='?'){
                cout << 'a';
            }else{
                cout << S[j];
            }
        }
        for(j=0; j<T.length(); j++){
            cout << T[j];
        }
        for(j=i+T.length(); j<S.length(); j++){
            if(S[j]=='?'){
                cout << 'a';
            }else{
                cout << S[j];
            }
        }
        cout << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }
    system("pause");
    return 0;
}