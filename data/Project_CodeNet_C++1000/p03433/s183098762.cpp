#include<iostream>
using namespace std;

int main(){
    int N,A;
    cin >> N >> A;
    int s=0;
    s = N%500;
    if(A >= s){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}