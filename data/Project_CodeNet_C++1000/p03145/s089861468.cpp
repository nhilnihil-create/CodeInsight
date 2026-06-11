#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    int ans=v[0]*v[1]/2;
    cout<<ans<<endl;
    return 0;
}