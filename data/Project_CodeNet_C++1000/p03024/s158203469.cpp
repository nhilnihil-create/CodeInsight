#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    string S;cin>>S;
    int cnt=0;
    REP(i,S.size())if(S[i]=='o')cnt++;
    cout<<(cnt>=8||((15-S.size())+cnt)>=8?"YES":"NO")<<endl;
}