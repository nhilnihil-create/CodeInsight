#include<bits/stdc++.h>
using namespace std;
string S;
int main(){
    cin>>S;
    int a{(int)count(S.begin(),S.end(),'a')},b{(int)count(S.begin(),S.end(),'b')},c{(int)count(S.begin(),S.end(),'c')};
    int min_n{min(a,min(b,c))},max_n{max(a,max(b,c))};
    if(max_n>min_n+1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
