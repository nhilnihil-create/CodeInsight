#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,i,arare;
    char s;

    arare = 0;

    cin >> N;
    
    rep(i,N){
        cin >> s;
        if(s == 'Y'){
            arare = 1;
        }
    }
    if(arare == 1){
        cout << "Four";
    }
    else{
        cout << "Three";
    }
}
