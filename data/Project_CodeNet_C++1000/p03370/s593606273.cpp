#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> m(n);
    int sum=n;
    for(int i=0;i<n;i++){
        cin>>m.at(i);
        x-=m.at(i);
    }
    sort(m.begin(),m.end());
    sum+=x/m.at(0);
    cout<<sum<<endl;
    
}