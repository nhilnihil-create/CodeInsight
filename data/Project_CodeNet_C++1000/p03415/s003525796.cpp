#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
    char a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            if(i==j)cout<<a[i][j];
        }
    }
    
}