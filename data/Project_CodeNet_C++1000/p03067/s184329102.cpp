#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    string s;
    if((a<c)^(c<b)^1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
