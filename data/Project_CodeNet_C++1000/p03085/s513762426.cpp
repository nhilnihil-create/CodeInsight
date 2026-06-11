#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    char s;
    cin>>s;
    if(s=='A')cout<<"T"<<endl;
    else if(s=='T')cout<<"A"<<endl;
    else if(s=='C')cout<<"G"<<endl;
    else cout<<"C"<<endl;

    return 0;
}