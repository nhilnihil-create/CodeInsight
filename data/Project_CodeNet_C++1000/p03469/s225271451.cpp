#include <bits/stdc++.h>
using namespace std;

int main(){
    char date[10];
    for(int i=0;i<10;i++){
        cin>>date[i];
    }
    date[3]='8';
    for(int i=0;i<10;i++){
        cout<<date[i];
    }
}