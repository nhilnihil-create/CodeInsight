#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int one,k;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            one=i;
            break;
        }
    }
    cin>>k;
    if(one>=k){
        cout<<"1"<<endl;
    }
    else{
        cout<<s[one]<<endl;
    }
    return(0);
}