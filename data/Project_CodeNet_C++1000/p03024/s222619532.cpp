#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int count=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='o') {
            count++;
        }
    }
    if (count+15-s.size()>=8) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}