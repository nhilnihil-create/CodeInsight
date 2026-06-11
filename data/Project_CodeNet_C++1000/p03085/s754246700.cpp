#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    char c;
    cin >> c;
    
    switch(c){
        case 'A': 
            cout << 'T';
            break;
        case 'T': 
            cout << 'A';
            break;
        case 'C':
            cout << 'G';
            break;
        case 'G':
            cout << 'C';
            break;
    }
    cout << endl;
}
