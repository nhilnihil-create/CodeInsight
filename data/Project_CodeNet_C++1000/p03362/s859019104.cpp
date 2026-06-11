#include<bits/stdc++.h>
using namespace std;
bool prime(int x){
    for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;
    return 1;
}
int main(){
    int n;
    cin>>n;
    for(int i=11;n;i+=5){
        if(prime(i)){
            cout<<i<<endl;
            n--;
        }
    }
    return 0;
}