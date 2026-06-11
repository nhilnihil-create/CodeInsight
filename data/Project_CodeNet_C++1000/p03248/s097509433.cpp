#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<pair<int,int>> ans;
    if(s[n-1]=='1' || s[0]=='0'){
        cout<<"-1\n";
        return 0;
    }
    bool flag=false;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-2-i]){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"-1\n";
        return 0;
    }
    int siz=1,hi=1;
    for(int i=1;i<n/2;i++){
        if(siz==i && s[i]=='1'){
            ans.emplace_back(hi,siz+1);
            siz++;
            hi=siz;
        }
        else if(s[i]=='1'){
            ans.emplace_back(hi,siz+1);
            siz++;
            hi=siz;
            while(siz<=i){
                ans.emplace_back(hi,siz+1);
                siz++;
            }
        }
    }
    if(n%2==0 && siz==n/2){
        auto new_ans=ans;
        for(auto i:new_ans){
            ans.emplace_back(n+1-i.first,n+1-i.second);
        }
        ans.emplace_back(siz,n+1-siz);
    }
    else{
        ans.emplace_back(hi,siz+1);
        siz++;
        hi=siz;
        while(siz<n){
            ans.emplace_back(hi,siz+1);
            siz++;
        }
    }
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}