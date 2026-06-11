#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int min=INT_MAX;
    for(int i=0;i<=v.size()-k;i++)
    {
        if(min>v[i+k-1]-v[i]){
            min=v[i+k-1]-v[i];
        }
    }
    cout<<min;
}