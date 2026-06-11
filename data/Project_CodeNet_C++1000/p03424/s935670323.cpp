#include <iostream>
using namespace std;
int main(){
    int N;
    bool count = false;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        string S;
        cin >> S;
        
        if(S != "Y"){
            continue;
        }
        else if(S == "Y"){
            count = true;
            break;
        }
    }
    if(count){
        cout << "Four" << endl;
    }
    else{
        cout << "Three" << endl;
    }
}