#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int ln=0,rn=1e9;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        ln=max(l,ln);
        rn=min(r,rn);
    }
    if(ln<=rn)cout<<rn-ln+1<<endl;
    else cout<<0<<endl;
    return 0;
}