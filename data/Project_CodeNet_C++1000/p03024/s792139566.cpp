#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    int count = 0;
    for(int i=0;i<S.length();i++){
        if(S[i] == 'x'){
            count++;
        }
    }
    if(count >= 8)cout << "NO" << endl;
    else cout << "YES" << endl;
}
