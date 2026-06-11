#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int count = 0;
    if(a < b){
        swap(a,b);
    }
    for(int i=b; i>=1; i--){
        if(a%i == 0 && b%i == 0){
            count += 1;
        }
        if(count == k){
            cout << i << endl;
            return 0;
        }
    }    
}