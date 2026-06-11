#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int sum=0;
    int prev=0;
    for(int i=0;i<n;i++)
    {
        if(prev<v[i]){
            sum+=v[i]-prev;
        }
        prev=v[i];
    }
    cout<<sum<<endl;
}