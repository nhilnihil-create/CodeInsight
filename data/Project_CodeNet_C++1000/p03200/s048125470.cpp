#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
long long  cnt=0,sum=0;
for(int i=0;i<s.size();i++){
    if(s[i]=='W'){
        sum+=(i-cnt);
        cnt++;
    }
}
cout<<sum;
}