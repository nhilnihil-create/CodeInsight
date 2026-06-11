#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    for (int i=1; i<k+1; i++) {
        if (i%2!=0) {
                b += a/2;
            a = a/2;
        }else{
                a += b/2;
            b = b/2;
            }
    }
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}