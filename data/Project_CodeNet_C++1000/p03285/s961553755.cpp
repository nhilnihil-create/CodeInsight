#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (size_t i = 0; i < 10000; i++)
    {
        if((N-4*i)%7 == 0) {
            
        cout << "Yes" << endl;
        break;
        } 
        if(N<4*i+4){
            cout << "No" << endl;
            break;
        }
    }
    

    return 0;
}