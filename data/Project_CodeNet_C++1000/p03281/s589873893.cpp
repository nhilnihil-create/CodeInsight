#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    int bread;

    if (N%2==0) {
        bread=N-1;
    }
    else {
        bread=N;
    }

    int kaage=0;
    int define=0;
    for (int i=1; i<bread+1; i+=2) {
        for (int j=1; j<bread; j++) {
            if (i%j==0) {
                kaage++;
            }
            else if (j==i-1 && kaage!=8) {
                kaage=0;
            }
            else if (j==i-1 && kaage==8) {
                define++;
            }
        }
    }
    cout << define << endl;
}
            
            
            
            
