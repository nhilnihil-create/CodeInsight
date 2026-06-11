#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int N;
    string S;
    cin>>N>>S;
    int r=0,b=0;
    for(int i=0;i<N;i++){
        if(S[i]=='R') r++;
        else b++;
    }
    if(r>b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
