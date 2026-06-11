#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x.at(i);
    }
    vector<int> y(n);
    for(int i=0;i<n;i++){
        cin>>y.at(i);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int z=x.at(i)-y.at(i);
        if(z>0) sum+=z;
    }
    cout<<sum<<endl;
}