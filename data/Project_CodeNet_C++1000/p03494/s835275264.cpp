#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    bool even=true;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]%2!=0)
        {
            even=false;
        }
    }
    int count=0;
    while(even)
    {
        count++;
        for(int i=0;i<n;i++)
        {
            v[i]/=2;
            if(v[i]%2!=0)
            {
                even=false;
                break;
            }
        }
    }
    cout<<count;
}