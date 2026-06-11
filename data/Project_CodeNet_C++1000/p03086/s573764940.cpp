#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C'){
            cnt++;
            if(i==s.size()-1){ans=max(ans,cnt);}
        }else{
            ans=max(cnt,ans);
            cnt=0;
        }
    }
    cout<<ans<<endl;

    return 0;
}