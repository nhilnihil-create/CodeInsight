#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){

    string S;
    int w;
    
    cin >> S;
    cin >> w;
    
    for(int i = 0; i < S.size(); i += w){
        cout << S.substr(i,1);
    }
    cout << endl;
        
}