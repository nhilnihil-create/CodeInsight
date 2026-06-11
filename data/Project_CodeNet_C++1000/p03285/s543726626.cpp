#include<iostream>
using namespace std;
int main(){
    int N;
    bool can = false;
    cin >> N;
    while(N >= 4){
        if(N % 4 == 0 || N % 7 == 0){
            can = true;
            break;
        }
        N -= 4;
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}