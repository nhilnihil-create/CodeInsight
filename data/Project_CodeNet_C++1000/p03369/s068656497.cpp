#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=700;
    string s;
    cin>>s;
    for(int i=0;i<3;i++)
    if(s.at(i)=='o')
    ans+=100;
    cout<<ans<<endl;
}