#include<iostream>
using namespace std;

int main(){
    int n, sum=0;
    cin>>n;
    int l[n];
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
        sum += l[i];
    }
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] >= sum-l[i])
        {
            flag=1;
        }
        
    }
    if (flag==1)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    
    
    
    
}