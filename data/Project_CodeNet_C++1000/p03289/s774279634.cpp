#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    string S;
    cin >> S;
    bool j1 = true;
    bool j2 = true;
    bool j3 = true;

    if(S.at(0) != 'A'){
        j1 = false;
    }
    else{
        S.at(0) = 'a';
    }

    int count =0;
    for(int i=2; i<=S.size()-2; i++){
        if(S.at(i)=='C'){
            count++;
            S.at(i) = 'c';
        }
    }
    if(count != 1){
        j2 = false;
    }

    for(int i=0; i<S.size(); i++){
        if(isupper(S.at(i))){
            j3 = false;
        }
    }

    if(j1 && j2 && j3){
        cout << "AC" << endl;
    }
    else{
        cout << "WA" << endl;
    }
}
