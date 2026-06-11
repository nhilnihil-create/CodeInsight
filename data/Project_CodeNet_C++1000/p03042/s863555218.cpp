#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    string S;
    cin >> S;
    if((S[0]== '0' && S[1] != '0' ) || ( S[0]== '1' && (S[1]=='0' || S[1]=='1' || S[1]=='2') ) ){
        if((S[2]== '0'&& S[3] != '0' ) || ( S[2]== '1' && (S[3]=='0' || S[3]=='1' || S[3]=='2') ) ){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "MMYY" << endl;
        }
    }else{
        if((S[2]== '0' && S[3] != '0' ) || ( S[2]== '1' && (S[3]=='0' || S[3]=='1' || S[3]=='2') ) ){
            cout << "YYMM" << endl;
        }else{
            cout << "NA" << endl;
        }
    }
}