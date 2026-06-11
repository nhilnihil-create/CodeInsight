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
    int result=0;
    for(int i=0;i<n;i++)
    {
        while(v[i]%2==0){
            v[i]/=2;
            result++;
        }
    }
    cout<<result;
}