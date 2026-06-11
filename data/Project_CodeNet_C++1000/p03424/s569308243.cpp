#include <bits/stdc++.h>
using namespace std;

int main(){
    bool yellowFlag = false;
    int N;
    cin >> N;
    
    for(int i = 0; i < N ; i++){
        string color;
        string yellow = "Y";
        cin >> color;
        if(color == yellow)yellowFlag =true;    
    }

    if(yellowFlag){
        cout << "Four" << endl;
    }else{
        cout << "Three" << endl;
    }
}