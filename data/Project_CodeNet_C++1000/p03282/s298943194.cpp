#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    long long int k;
    cin >> S >> k;
    for(long long int i=0;i<S.length();i++){
        if(S[i]!='1'){
            cout << S[i] << endl;
            return 0;
        }
        else if(S[i]=='1' && i==k-1){
            cout << '1' << endl;
            return 0;
        }
    }
}