#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long ans=1; cin>>n;
    string s; cin>>s;
    map<char,int> check;
    for(int i=0; i<n; i++) {
        if(check.count(s[i])) check[s[i]]+=1;
        else{
            check[s[i]]=1;
        }
    }
    for(auto a:check){
        int val=a.second;
        ans = ans*(val+1)%1000000007;
    }
    cout << ans-1 << endl;
}