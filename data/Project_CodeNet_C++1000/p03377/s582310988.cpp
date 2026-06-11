#include <iostream>

using namespace std;

int main(){
    int A,B,X;

    cin >> A >>B >>X;
    
    if(X<=A+B)
        if(X<A)
            cout << "NO";
        else
            cout << "YES";
    else
        cout << "NO";
    
    
        
    return 0;
}
