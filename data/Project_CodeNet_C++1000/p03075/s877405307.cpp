#include <bits/stdc++.h>
using namespace std;

int main() {
    int s[5];
    for(int i=0;i<5;++i){
        cin>>s[i];
    }
    int k;cin>>k;
    if(s[4]-s[0]<=k)cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
	return 0;
}