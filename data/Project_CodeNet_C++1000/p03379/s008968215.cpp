#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n),r(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    r=v;
    sort(v.begin(),v.end());
    int median=n/2-1;
    for(int i=0;i<n;i++)
    {
        if(v[median]>=r[i]){
            cout<<v[median+1]<<endl;
        }
        else
        {
            cout<<v[median]<<endl;
        }
    }
}