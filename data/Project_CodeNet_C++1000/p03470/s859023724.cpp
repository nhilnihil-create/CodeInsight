#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n,i,p;
    set<int> s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>p;
        s.insert(p);
    }
    cout<<s.size()<<'\n';
    return(0);
}