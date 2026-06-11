#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;

    int sum=0,b=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T') sum++;
        else{
            if(sum>b){
                b=sum;
                sum=0;
            }
        }
    }

    if(sum>b) cout<<sum<<endl;
    else cout<<b<<endl;
}