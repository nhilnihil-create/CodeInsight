#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int>v1(n),v2(m);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>v2[i];
    }
    int x1=*max_element(v1.begin(),v1.end());
    int y1=*min_element(v2.begin(),v2.end());
    int z=x1+1;
    if(z<=y1&&z<=y&&z>x){
        cout<<"No War\n";
    }
    else
    {
        cout<<"War\n";
    }
}