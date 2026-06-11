#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>l(m);
    vector<int>r(m);
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int a=r[0]-l[m-1]+1;
    if(a<0)a=0;
    cout<<a;
}