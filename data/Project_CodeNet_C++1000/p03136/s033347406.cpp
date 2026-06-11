#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    cin>>n;
    int t=n;
    vector<int>v;
    vector<int>::iterator y;
    while(t--)
    {
      cin>>x;
      v.push_back(x);
    }
    int m=*max_element(v.begin(),v.end());
    int p=accumulate(v.begin(),v.end(),0)-m;
    if(p>m)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
    return 0;
}