#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,n_r=0; cin>>n;
    string s; cin>>s;
    for(char c:s) {
        if(c=='R') n_r++;
    }
    cout << (n_r>n/2?"Yes":"No") << endl;
}