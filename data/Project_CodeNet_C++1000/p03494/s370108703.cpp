#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n, count=0;
    cin >> n;
    
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    while(true){
        for(int i=0; i<n; ++i){
            if(A[i]%2){
                cout << count << endl;
                return 0;
            }
        }    
        for(int i=0; i<n; ++i){
            A[i] /= 2; 
        }
        ++count;
    }
}