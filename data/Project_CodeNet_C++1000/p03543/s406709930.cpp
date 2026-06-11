#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main(){
    string s;
    cin>>s;
    int cnt=1;
    bool flg=false;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            cnt++;
        }else{
            cnt=1;
        }
        if(cnt>=3){
            flg=true;
        }
    }
    cout<<(flg?"Yes":"No")<<endl;
    return 0;
}