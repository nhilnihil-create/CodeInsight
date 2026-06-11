#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
const int MOD = 1000000007;
using namespace std;

int main(){
    int N,A;
	cin >> N >> A;
    if((N % 500) >A){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}