#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cin>>s;
    int len = (int)s.length();
    /*vector<int >a(len,0);
    if(s[0]=='B')a[0]=1;
    else a[0]=0;
    for(int i=1;i<len;i++){
        if(s[i]=='B')a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    */
    long long count=0;int cb=0;
    for(int i=0;i<len;i++){
        if(s[i]=='B')cb++;
        if(s[i]=='W')count+=cb;
    }
    cout<<count;
}