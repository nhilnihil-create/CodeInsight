/**
 *  author: mahfuzz
 *  created: 17.04.2020
**/
 
#include <iostream>
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    if(n % 2 == 0)
        cout << n << "\n";
    else
        cout << n * 2 << "\n";
    
        
    return 0;
}