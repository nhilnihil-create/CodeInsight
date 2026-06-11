#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>m(n);
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        if(min>m[i]){
            min=m[i];
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        result+=m[i];
    }
    x-=result;
    int total=x/min;
    total+=n;
    cout<<total;
}