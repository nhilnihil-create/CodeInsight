#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a,b,k;cin >> a >> b >> k;
    for(int i = 0; i < k; i++){
        if(a%2 != 0) a = a -1;
        b += a/2;
        a = a/2;
       // cout << a << " " << b << endl;
        i++;
        if(i == k)break;
        if(b%2 != 0) b = b -1;
        a = a + b/2;
        b = b/2;
        //cout << a << endl;
    }
    cout << a <<  " " << b << endl;
        
}