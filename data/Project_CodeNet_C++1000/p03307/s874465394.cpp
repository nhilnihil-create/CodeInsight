#include <iostream>

using namespace std;

int main(){
    int N, c=2, v=0;

    cin >> N;
    if(N%2){
        cout << N*2;
    }
    else{
        cout<< N;
    }

    return 0;
}
