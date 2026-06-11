#include <iostream>
#include <string>
using namespace std;

int otakTakeshi;
string input, tambah="+";

int main (){
    cin>>input;
    for (int i=0; i<=3; i++){
        if (input [i]==tambah [0]){
            otakTakeshi++;
        } else {
            otakTakeshi--;
        }
    }
    cout<<otakTakeshi<<endl;
}