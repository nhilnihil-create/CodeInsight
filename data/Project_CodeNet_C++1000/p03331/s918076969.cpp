#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=100000+1;
    for(int i=1;i<n;i++){
        string s=to_string(i),t=to_string(n-i);
        int a=s.size(),b=t.size();
        int cnt=0;
        for(int j=0;j<a;j++) cnt+=s[j]-'0';
        for(int j=0;j<b;j++) cnt+=t[j]-'0';
        if(cnt<ans) ans=cnt;
    }
    cout<<ans<<endl;
}