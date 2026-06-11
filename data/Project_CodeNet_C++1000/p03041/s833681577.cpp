#include<bits/stdc++.h>
using namespace std;
char lower(char x){
    if(x=='A'){
         return 'a';
    }
    else if(x=='B'){
        return 'b';
    }
    else if(x=='C'){
        return 'c';
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    char str[n];
    cin>>str;
    for(int i=0;i<n;i++){
        if(i==k-1){
            cout<<lower(str[i]);
        }
        else{
            cout<<str[i];
        }
    }
}
