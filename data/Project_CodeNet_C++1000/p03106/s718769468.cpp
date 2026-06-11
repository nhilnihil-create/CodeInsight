#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b,k;
    cin >> a >> b >> k;

    int x = __gcd(a,b);
    for(int i=x; i>=1; i--){
        if(x%i==0){
            k--;
            if(k==0){
                cout << i << endl;
            }
        }
    }
    return 0;
}