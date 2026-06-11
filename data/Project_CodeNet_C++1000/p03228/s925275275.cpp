#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k; cin>>a>>b>>k;
    for(int i=1; i<=k; i++){
        if(i%2==1){
            if(a%2==0){
                a=a/2;
                b+=a;
            }
            else{
                a=a-1; a=a/2;
                b+=a;
            }
        }
        else{
            if(b%2==0){
                b=b/2;
                a+=b;
            }
            else{
                b=b-1; b=b/2;
                a+=b;
            }
        }
    }
    cout << a << " " << b << endl;
}