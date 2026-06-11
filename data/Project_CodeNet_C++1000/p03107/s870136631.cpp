#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    int blue=0,red=0;
    cin>>s;
    int sum=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            red++;
        }
        else if(s[i]=='1'){
            blue++;
        }
    }
    cout<<sum-(max(blue,red)-min(blue,red))<<endl;
}

 