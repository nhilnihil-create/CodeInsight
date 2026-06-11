#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    string S;
    cin >> S;
    string T = "keyence";
    string R = S;
    string Q;
    for(int i = 0; i <S.size();i++){
        for(int j = i; j < S.size();j++){
            R = S;
            Q = R.erase(i,j-i);
            //cout << Q <<endl;
            if(Q == T){
                cout <<"YES"<<endl;
                return 0;
            }
        }
    }
    cout <<"NO"<<endl;
    return 0;
    
}       
    
    

