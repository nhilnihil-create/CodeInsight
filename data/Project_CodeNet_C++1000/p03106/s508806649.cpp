#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k,count=0;
    cin >> a >> b >> k;
    if(a>b) swap(a,b);
    for(int i=a;i>0;i--){
        if(a%i==0){
            if(b%i==0) count++;
            if(count==k){
                cout << i << '\n';
                return 0;
            }
        }
    }
}
