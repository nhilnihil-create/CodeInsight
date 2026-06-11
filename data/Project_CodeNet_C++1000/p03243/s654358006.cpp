#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    bool ok=false;
    while(ok==false){
        int a=n%10;
        int sub=n;
        sub=sub/10;
        int b=sub%10;
        sub=sub/10;
        int c=sub%10;
        if(a==b && a==c && b==c){
            ok=true;
        }else{
            n++;
        }
    }
    cout << n << endl;
    return 0;
}