#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i=0;i*7<=N;i++){
        if((N-i*7)%4==0){
            cout << "Yes";
            exit(0);
        }
    }
    cout << "No";
}