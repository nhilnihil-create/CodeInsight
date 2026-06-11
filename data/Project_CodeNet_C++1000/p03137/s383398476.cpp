#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(m),diff(m-1);;
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    {
        diff[i]=v[i+1]-v[i];
    }
    sort(diff.begin(),diff.end());
    n--;
    m--;
    int s=m-n;
    if(s<0)s=0;
    int sum=0;
    for(int i=0;i<s;i++)
    {
        sum+=diff[i];
    }
    cout<<sum<<endl;
}