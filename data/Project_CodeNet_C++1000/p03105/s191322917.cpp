#include <iostream>
using namespace std;
int main(void){
    
    int A, B, C;
    cin >> A >> B >>C;
    
    int max_music = B / A;
    
    if(max_music >= C){
        cout << C << endl;
    }
    else{
        cout << max_music << endl;
    }
    
    
}
