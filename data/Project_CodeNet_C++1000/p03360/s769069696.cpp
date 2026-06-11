#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k;
    bool ok=true;
    long long big=0;
    cin >> a >> b >> c >> k;
    big=max(a,(max(b,c)));
    if(big==a){
        for(int i=0;i<k;i++){
            big *= 2;
        }
        cout << big + b + c << endl;
        ok=false;
    }
    if(big==b&&ok){
        for(int i=0;i<k;i++){
            big *= 2;
        }
        cout << a + big + c << endl;
        ok=false;
    }
    if(big==c&&ok){
        for(int i=0;i<k;i++){
            big *= 2;
        }
        cout << a + b + big << endl;
        ok=false;
    }
    return 0;
}