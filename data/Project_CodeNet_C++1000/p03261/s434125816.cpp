#include <bits/stdc++.h>
using namespace std;
string a[150];
int n;
bool b=true;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       string t=a[i];
        if(t==a[j]&&i!=j){
                b=false;break;
    }}
    if(b==false)break;
}
if(b==false)cout<<"No";
else{
    for(int i=0;i<n-1;i++){
    string s=a[i];
    string t=a[i+1];
    int m=s.size();
    if(s[m-1]==t[0])
        b=true;
    else {
            b=false;break;}
}
if(b==false)cout<<"No";
else cout<<"Yes";}
return 0;

}
