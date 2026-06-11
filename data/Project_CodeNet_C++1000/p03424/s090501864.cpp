#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    char arare[n];
    for(int i=0; i<n; i++){
        cin >> arare[i];
    }
    bool ans=false;
    for(int i=0; i<n; i++){
        if(arare[i] == 'Y'){
            ans = true;
        }
    }

    if(ans){
        cout << "Four" << endl;
    }
    else{
        cout << "Three" << endl;
    }
}