#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    
    int count=0;
    int count9=0;
    while(1){
        if(n%10==9) count9++;
        count++;
        if(n/10<1) break;
        n/=10;
    }

    if(count==count9){
        cout << 9*count << endl;
    }
    else if(count==count9+1){
        if(n==9){
            cout << 8+count9*9 << endl;
        }
        else{
            cout << n+count9*9 << endl;
        }
    }
    else{
        cout << n-1+(count-1)*9 << endl;
    }
}