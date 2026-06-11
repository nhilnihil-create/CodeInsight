#include <bits/stdc++.h>

using namespace std;


int main() {

    int a, b, c, r;
    cin >> a >> b;

    if(a<=b) {

        for(int i=a; i<=b; i++) {

            r = a*b*i;

            if(r%2 != 0) {
                cout << "Yes" << endl;
                break;
            } 
            else if(r%2 ==0 && i == b) {
                 cout << "No" << endl;
            }
        }

    }
    else if(b<a) {

        for(int i=b; i<=a; i++) {
            
            r = a*b*i;

            if(r%2 != 0) {
                cout << "Yes" << endl;
                break;                
            }  
            else if(r%2 ==0 && i == b) {
                 cout << "No" << endl;
            }
        }
    }

    return 0;
}

