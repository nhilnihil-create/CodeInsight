#include <bits/stdc++.h>
using namespace std;

int main(){
   
    map<int,int> A;
    bool ans=true;
    for(int i=0;i<6;i++){
        int a;cin>>a;
        A[a]++;
        if(A[a]==3) ans=false;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
