#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    if(N%111==0){
        cout<<N<<endl;
    }else if(N<(N/100)*111){
        cout<<(N/100)*111<<endl;
    }else if(N>(N/100)*111){
        cout<<((1+(N/100))*111)<<endl;
    }
}
