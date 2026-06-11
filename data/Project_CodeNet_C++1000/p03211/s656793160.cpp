#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=1e8;
    int z;
    for(int i=0;i<s.size()-2;i++){
    int a=(s.at(i)-'0')*100;
    int b=(s.at(i+1)-'0')*10;
    int c=(s.at(i+2)-'0');
    int x=a+b+c;
    ans=min(abs(x-753),ans);
    }
    cout<<ans<<endl;
}