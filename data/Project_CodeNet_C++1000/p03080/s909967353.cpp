#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    string s;
    cin>>n>>s;
    int count=0;
    for (int i=0;i<n;i++) {
        if (s[i]=='R') {
            count++;
        }
    }
    if (n-count<count) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}