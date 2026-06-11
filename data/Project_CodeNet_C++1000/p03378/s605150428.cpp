#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int>v(n+1,0);
    for(int i=0;i<m;i++)
    {
        int element;
        cin>>element;
        v[element]=1;
    }
    int count=0;
    for(int i=1;i<x;i++)
    {
        count+=v[i];
    }
    cout<<min(count,m-count);
}