#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string S;
    cin >> S;

    int count = 0;
    for (int i = 0; i < S.length(); i++){
        if (S[i] == 'x'){
            count ++;
        }
    }

    if (count <= 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}