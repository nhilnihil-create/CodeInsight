#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;

    int count = 0;

    for(int a=0; a<30 ; a++){
        for(int b=0; b<20 ; b++){
            int total = 4*a + 7*b;
            if(total == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
