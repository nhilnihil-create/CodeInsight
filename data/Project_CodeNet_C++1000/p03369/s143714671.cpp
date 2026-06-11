#include<iostream>
using namespace std;

const int ramen=700;
const int toping=100;

int main(){
    char S[3];
    for(int i=0;i<3;i++){
        cin >> S[i];
    }
    int counter=0;

    for(int j=0;j<3;j++){
        if(S[j]=='o'){
            ++counter;
            //cout << "toping add\n" <<endl;
        }
    }

    cout << ramen+counter*toping <<endl;


}