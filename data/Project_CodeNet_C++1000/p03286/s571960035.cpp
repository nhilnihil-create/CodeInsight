#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    if(N==0){
        cout << 0 << endl;
        return 0;
    }
    string S = "";

    for(long long int i=1;N!=0;i++){
        long long int div = pow(2,i);
        if(abs(N)%div != 0){
            if(i%2==1){
                N -= pow(2,i-1);
            }else{
                N += pow(2,i-1);
            }
            S += '1';
        }else{
            S += '0';
        }
    }

    reverse(S.begin(),S.end());

    cout << S << endl;
}