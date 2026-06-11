#include<bits/stdc++.h>
using namespace std;

#define int long long int 


int32_t main()
{
    // int n;
    // cin>>n;
    vector<int> v(3,0);
    for(int i=0;i<3;i++)
    cin>>v[i];
    cout<<*max_element(v.begin(),v.end()) - *min_element(v.begin(),v.end())<<endl;
}