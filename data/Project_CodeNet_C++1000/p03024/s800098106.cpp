#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int ans=0;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='o') ans ++;
    }
    cout <<(ans+15-n>=8?"YES":"NO") << endl;
}