#include "./bits/stdc++.h"
using namespace std;

int MIN = (1<<21);
string S;
int N=753;

int main(){
    cin >> S;
    for(int i=0;i<S.size()-2;i++){
        int X=100*(int(S[i])-48)+10*(int(S[i+1]-48))+(int(S[i+2])-48);
        if(MIN > abs(X-N)){
            MIN=abs(X-N); 
        }

    }
    cout << MIN << endl;
    return 0;
}