#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,total=0;

    cin>>n;

    while(n){
        total += n%10;
        n = n/10;
    }

    if(total==1)
        cout<<10<<endl;
    else
        cout<<total<<endl;

    return 0;
}