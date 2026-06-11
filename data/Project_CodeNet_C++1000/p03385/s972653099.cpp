#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S == "abc" || S == "acb"){
        cout << "Yes" <<endl;
    }
    else if(S == "bac" || S == "bca"){
        cout << "Yes" << endl;
    }
    else if(S == "cab" || S == "cba"){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" <<endl;
    }
}
