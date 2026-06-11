#include <bits/stdc++.h>
using namespace std;
int main(){
int A;
char B;
int C;
char D;
int E;
cin>>A>>B>>C>>D>>E;
if(A<2019){
    cout<<"Heisei"<<endl;
}
else if(A==2019){
    if(C<=4){
        cout<<"Heisei"<<endl;
    }
    else 
    cout<<"TBD"<<endl;
}
}