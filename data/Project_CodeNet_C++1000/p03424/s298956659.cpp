#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        if(S == "Y"){
            ans++;
        }
    }
    
    if(ans == 0){
        cout << "Three" << endl;
    }
    else{
        cout << "Four" << endl;
    }
    
    return 0;
}
