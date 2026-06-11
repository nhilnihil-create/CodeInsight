#include<iostream>
#include<string>

using namespace std;

int main(){
    string S;
    cin >> S;
    int count,prise = 700;
    if(S[0] == 'o')prise+=100;
    if(S[1] == 'o')prise+=100;
    if(S[2] == 'o')prise+=100;
    cout << prise << endl;
}