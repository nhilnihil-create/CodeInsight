#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,c[100],v[100];
    cin>>n;
    for(int i=0;i<n;i++)	cin>>v[i];
    for(int i=0;i<n;i++)   cin>>c[i];
    vector<int>r;
    for(int i=0;i<n;i++){r.push_back(v[i]-c[i]); }
    sort(r.begin(),r.end());
    int sum=0;
    for(int i=0;i<n;i++){ if(r[i]>0){   sum+=r[i]; }
    }
    cout<<sum<<endl;
}