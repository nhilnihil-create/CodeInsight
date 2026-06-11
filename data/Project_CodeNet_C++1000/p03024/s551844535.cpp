#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string c;
    cin >> c;
    
    int nx = 0; 
    for(int i=0; i<c.size() ;i++){
        if(c.at(i)=='x'){
            nx++;
        }
    }
    // cout << nx << endl;
    if(nx>= 8){
        cout<< "NO" <<endl;
    }else{
        cout<< "YES" <<endl;
    }
}