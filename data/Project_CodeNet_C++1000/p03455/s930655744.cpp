#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int a,b,ab;

int main(){
    
cin >> a;
    cin >> b;

    ab = a * b;
    if(ab % 2 == 0){
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }
 
    
    
    return 0;
}
