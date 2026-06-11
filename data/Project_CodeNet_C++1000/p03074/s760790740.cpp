#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,MAX,ans;
string s;
char L;
vector<int> v;
int main(void){
    cin>>n>>k>>s;
    s='1'+s+'1';
    cnt=0;
    L='1';
    cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]=='0'){
            if(L=='0')cnt++;
            else{L='0';v.push_back(cnt);cnt=1;}
        }
        else{
            if(L=='1')cnt++;
            else{L='1';v.push_back(cnt);cnt=1;}
        }
    }
    v.push_back(cnt);
    if(v.size()<=2*k+1){
        for(int x:v)ans+=x;
        cout<<ans-2<<endl;
        return 0;
    }
    
    for(int i=0;i<2*k+1;i++)ans+=v[i];
    MAX=ans-1;
    for(int i=0;i<(v.size()-2*k-1)/2;i++){
        ans-=v[i*2]+v[i*2+1];
        ans+=v[2*(k+i)+1]+v[2*(k+i)+2];
        if(i==(v.size()-2*k-1)/2-1)MAX=max(ans-1,MAX);
        else MAX=max(ans,MAX);
    }
    cout<<MAX<<endl;
}
