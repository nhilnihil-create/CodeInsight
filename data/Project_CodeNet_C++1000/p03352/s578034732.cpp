#include<bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;

    vector<bool> isExp(1010, false);
    isExp.at(1) = true;
    for(int i=2; i<=1000; ++i){
        for(int j=2; pow(i, j)<=1000; ++j){
            isExp.at((int)pow(i, j)) = true;
        }
    }

    for(int i=X; i>0; --i){
        if(isExp.at(i)){
            cout << i << endl;
            break;
        }
    }
}