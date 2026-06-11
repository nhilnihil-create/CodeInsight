#include <iostream>
#include <string>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    int i,j;
    int check=0;
    int ans=-1;

    for(i=S.length()-T.length(); i>=0; i--){
        for(j=0; j<T.length(); j++){
            if(S[i+j]!='?' && S[i+j]!=T[j]) check=1;
        }
        if(check==0){
            for(j=0; j<T.length(); j++){
                S[i+j]=T[j];
            }
            ans=i;
            i=-1;
        }
        else check=0;
    }

    if(ans==-1) cout << "UNRESTORABLE" << endl;
    else{
        for(i=0; i<S.length(); i++){
            if(S[i]=='?') S[i]='a';
            cout << S[i];
        }
        cout << endl;
    }

    return 0;
}