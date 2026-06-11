#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k,i;
    cin >> a >> b >> k;
    if(b-a+1<2*k){
        int n=b-a+1;
        for(i=0;i<n;i++){
            cout << a << endl;
            a++;
        }
    }
    else{
        for(i=0;i<k;i++){
            cout << a << endl;
            a++;
        }
        b -= (k-1);
        for(i=0;i<k;i++){
            cout << b << endl;
            b++;
        }
    }
    return 0;
}