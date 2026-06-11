#include  <iostream>
using namespace std;

int main (void){
    string n;
    cin >> n;

    if (n[1] == n[2] && (n[0] == n[1] || n[2] == n[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}
