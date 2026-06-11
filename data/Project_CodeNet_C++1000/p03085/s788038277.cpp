#include <bits/stdc++.h>

using namespace std;

int main(){
    string b;
    cin >> b;
    for(int i=0;i<b.size();i++){
        if(b[i]=='A'){
            cout << 'T' << endl;
        }else if(b[i]=='T'){
            cout << 'A' << endl;
        }else if(b[i]=='G'){
            cout << 'C' << endl;
        }else{
            cout << 'G' << endl;
        }
    }
}