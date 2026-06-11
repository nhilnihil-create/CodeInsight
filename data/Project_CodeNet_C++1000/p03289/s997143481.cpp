#include <bits/stdc++.h>
using namespace std;
string s;
int k,m,n,x,y,z;
bool b=false;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s;
for(int i=0;i<s.size();i++){
        if(s[i]=='C'){
                k++;m=i;
 
}}
y=s.size();
if(k==1 && s[0]=='A'&& m>=2 && m<=y-2){
    for(int i=1;i<y;i++){
        if(islower(s[i])){
            x++;
    }}
    y-=2;
    if(x==y)cout<<"AC";
    else cout<<"WA";
 
}
else cout<<"WA";
return 0;
}