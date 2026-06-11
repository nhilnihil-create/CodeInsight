#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
const int MOD = 1000000007;
using namespace std;

int main(){
    int N;
	cin >> N;
    int A;
    int min=1000000000, max=1;
    for (int i = 0; i < N; i++){
        cin >> A;
        if (A >= max){
            max = A;
        }
        if (A <= min){
            min = A;
        }
    }

    cout << max-min << endl;
}