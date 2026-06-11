#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    priority_queue<int> ans;
    ans.push(0);
    for(int i=0;i<s.size();i++){
        int cnt=0;
        for(int j=i;j<s.size();j++){
            if(s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T')
            cnt++;
            else
            break;
        }
        ans.push(cnt);
    }
    cout<<ans.top()<<endl;
}