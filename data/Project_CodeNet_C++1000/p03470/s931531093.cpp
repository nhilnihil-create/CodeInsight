#include<bits/stdc++.h>
using namespace std;
 
int main(){
    set<int>se;
    int q,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q;
        se.insert(q);
    }
    cout<<se.size()<<endl;
    return(0);
}