#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    
    vector<int> a;
    
    for(int i=0;i<N;i++)
    {
        int Temp;
        cin>>Temp;
        
        a.push_back(Temp);
        
    }
    
    sort(a.begin(),a.end(),greater<int>());
    
    int max,gokei;
    gokei=0;
    
    max=a[0];
    
    for(int i=1;i<N;i++)
    {
        gokei+=a[i];
    }
    
    if(gokei>max)
    {
        cout<<"Yes";
    }
    
    else
    {
        cout<<"No";
    }
}