#include <iostream>
//#include <vector>

using namespace std;

int main () {
    int A,B,C,D,E;
    cin >> A >> B>>C>>D>>E;
    int k;
    cin >> k;
    
    if(B-A >k) cout << ":(" << endl;
    else if(C-A > k) cout << ":(" << endl;
    else if(D-A > k) cout << ":(" << endl;
    else if(E-A > k) cout << ":(" << endl;
    
    else if(C-B > k) cout << ":(" << endl;
    else if(D-B > k) cout << ":(" << endl;
    else if(E-B > k) cout << ":(" << endl;
    
    else if(D-C > k) cout << ":(" << endl;
    else if(E-C > k) cout << ":(" << endl;
    
    else if(E-D > k) cout << ":(" << endl;
    else cout << "Yay!" << endl;
    return 0;    
}


