#include <iostream>
using namespace std;

int main(){
    int ab, bc, ca;
    cin >> ab >> bc >> ca;
    if(ab > bc && ab > ca){
        cout << bc * ca /2<<endl;
    }
    else if(bc > ab && bc > ca){
        cout << ab * ca /2<<endl;
    }
    else if(ca > ab && ca > bc){
        cout << ab * bc /2 <<endl;
    }    
    
}