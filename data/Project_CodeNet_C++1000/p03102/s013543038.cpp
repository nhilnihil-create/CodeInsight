#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin>>b.at(i);
    }
    int ans=0;
    int count=0;
    while(count<n){
        int z=0;
        for(int i=0; i<m; i++){
            int a;
            cin>>a;
            z+=a*b.at(i);
        }
        if(z+c>0) ans++;
        count++;
    }
    cout<<ans<<endl;

}