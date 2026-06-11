#include <iostream>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    char b;
    cin >> b;

    char ans;
    switch(b){
        case 'A':
            ans = 'T';
            break;
        case 'C':
            ans = 'G';
            break;
        case 'G':
            ans = 'C';
            break;
        case 'T':
            ans = 'A';
            break;
    }
    cout << ans << endl;
    return 0;
}
