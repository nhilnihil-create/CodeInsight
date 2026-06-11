#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int ans1=0,ans2=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0 && s[i]=='0'){
            ans1++;
        }
        if(i%2==1 && s[i]=='1'){
            ans1++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(i%2==1 && s[i]=='0'){
            ans2++;
        }
        if(i%2==0 && s[i]=='1'){
            ans2++;
        }
    }
    cout<<min(ans1,ans2)<<endl;
    return(0);
}
