#include<bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    long j;
    long log=0;
    for(int i=1;i<=n;i++){
        j=i*i;
        if(j>n){
            
            log=(i-1)*(i-1);
            cout << log <<endl;
            return 0;
        }
    }
    
}