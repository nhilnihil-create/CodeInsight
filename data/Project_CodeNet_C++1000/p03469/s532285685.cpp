#include<iostream>
#include<string>
using namespace std;

int main(){
    string S;
    cin >> S;
    string T;
    T = S.replace(3, 1, "8");
    cout << T << endl;
}