#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;
    
    for(int i=0;i<8;i++)
        S.pop_back();
    
    cout << S << endl;

}