    #include <iostream>
    #include <string.h>
     
    using namespace std;
     
    int main(){
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
     
        if(b == a){
            if(b==c) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    else {
           cout << "No" << endl;
    }
    }