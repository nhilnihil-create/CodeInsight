#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]*=-1;
    }
    sort(v.begin(),v.end());
    int first=0,second=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            first+=(v[i]*-1);
        }
        else
        second+=(v[i]*-1);
    }
    cout<<first-second;
}