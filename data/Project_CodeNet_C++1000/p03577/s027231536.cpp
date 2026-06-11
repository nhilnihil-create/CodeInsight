#include<bits/stdc++.h>
using namespace std;

string str;

int main(){
    cin>>str;
    str.erase(str.length()-8,str.length()-1);
    cout<<str<<endl;
    return 0;
}