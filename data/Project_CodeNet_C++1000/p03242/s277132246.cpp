#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    for(char c:s){
        cout<<(char)('9'+'1'-c);
    }
    cout<<endl;







    return 0;
}