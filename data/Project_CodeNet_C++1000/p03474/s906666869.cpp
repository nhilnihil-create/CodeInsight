#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,chk1=0,chk2=0;
    string s;
    cin>>a>>b;
    cin>>s;
    if(s.length()==a+b+1 && s[a]=='-'){
        for(int i=0;i<a;i++){
            if(s[i]<48 || s[i]>57){
                chk1=1;
                break;}
        }
       for(int j=a+1;j<s.length();j++){
            if(s[j]<48 || s[j]>57){
                chk2=1;
                break;}
        }

    if(chk1==0 && chk2==0) cout<<"Yes";
    else cout<<"No";
 }
 else cout<<"No";

    return 0;
}
