#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool ans=false;
    vector<char> s(n);
    for(int i=0;i<n;i++)
    cin>>s[i];
    for(int i=0;i<n;i++){
        if(s[i]=='Y'){
            ans=true;
            break;
        }
    }
    if(ans)
    cout<<"Four"<<endl;
    else
    cout<<"Three"<<endl;
}