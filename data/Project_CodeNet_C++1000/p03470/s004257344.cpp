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
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        int prev=v[i];
        bool inside=false;
        count++;
        while(i>=0&&v[i]==prev)
        {
            i--;
            inside=true;
        }
        if(inside){
            i++;
        }
    }
    cout<<count;
}