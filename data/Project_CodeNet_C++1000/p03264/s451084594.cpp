#include<iostream>
using namespace std;

int main(){

int k;
cin>>k;
int ec = 0;
int oc = 0;
for(int i = 1;i<=k;i++){
    if(i%2 == 0){
        ec++;
    }
    else{
        oc++;
    }
}

cout<<(ec*oc);
}
