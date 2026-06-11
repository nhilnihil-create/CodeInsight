#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> e(100001),o(100001);
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        if(i%2) o[v]++;
        else e[v]++;
    }
    int i=max_element(e.begin(),e.end())-e.begin();
    int j=max_element(o.begin(),o.end())-o.begin();
    int ans=0;
    if(i!=j) ans=n-o[j]-e[i];
    else{
        sort(e.rbegin(),e.rend());
        sort(o.rbegin(),o.rend());
        ans=min(n-e[0]-o[1],n-o[0]-e[1]);
    }
    cout<<ans<<endl;
}