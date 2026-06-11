#include<bits/stdc++.h>
using namespace std;
int main(){
    string S,T;
    cin >> S >> T;
    int flag=0;
    for(int i=0;i<S.length();i++){
        flag=0;
        for(int j=0;j<S.length();j++){
            if(S[(i+j)%S.length()]!=T[j]){flag++; break;}
        }
        if(flag==0){cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
}