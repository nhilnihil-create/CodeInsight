#include<iostream>
#include<string>
using namespace std;
int main (){
    string S;
    cin >> S;
    int count = 0;
    int y;
    for(int i = 0; i < 3; i++){
        if (S[i] == 'o') count++;
    }
    y = 700 + count*100;
    cout << y << endl;
}