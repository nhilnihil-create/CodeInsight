#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    
    int x = B/A;
    if(x>C){
        cout << C << endl;
    }else{
        cout << x << endl;
    }
}