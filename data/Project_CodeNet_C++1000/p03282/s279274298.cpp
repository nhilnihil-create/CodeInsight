#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin>>s;
    long long n;cin>>n;
    
    for(int i=0;i<n;++i){
        if(s[i]=='1' && n<=i+1){
            cout<<1<<endl;
            return 0;
        }
        else if(s[i]!='1'){
            cout<<s[i]<<endl;
            return 0;
        }
    }

	return 0;
}