#include<bits/stdc++.h>
using namespace std;
main(){
    string str;
    cin>>str;
    if(str.size()==1){cout<<"0"; return 0;}
    int num,i,one=0,zero=0,on=0,zr=0,tot1,tot2;
    for(i=0;i<str.size();i++){
        if(i%2==0) {if (str[i]=='1') zero++;}
        else {if (str[i]=='0')one++;}
        if(i%2==0) {if (str[i]=='0') on++;}
        else {if (str[i]=='1') zr++;}
    }
    tot1=zero+one;
    tot2=on+zr;
    cout<<min(tot1,tot2);
}