#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int i,n;
    cin>>s>>n;
    for(i=0;i<s.size();i+=n){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
