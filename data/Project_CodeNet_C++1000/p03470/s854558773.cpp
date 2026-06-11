#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
        s.insert(d[i]);
    }
    cout<<s.size()<<endl;
    return(0);
}