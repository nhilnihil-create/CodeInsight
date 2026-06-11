#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    bool flg = true;

    for(int i=0; i<A; ++i){
        if(S.at(i)-'0' >= 0 && S.at(i)-'0' <= 9) ;
        else {
            flg = false;
            break;
        }
    }

    if(S.at(A) == '-') ;
    else {
        flg = false;
    }

    for(int i=(A+1); i<(A+B+1); ++i){
        if(S.at(i)-'0' >= 0 && S.at(i)-'0' <= 9) ;
        else {
            flg = false;
            break;
        }
    }

    if(flg == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}