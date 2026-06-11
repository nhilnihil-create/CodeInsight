#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    vector<long long int>a(n),b(n),c(n);
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(long long int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    vector<long long int>countb(n,0);
    for(long long int i=0;i<b.size();i++)
    {
        auto it=upper_bound(c.begin(),c.end(),b[i]);
        countb[i]=c.end()-it;
    }
    long long int  prev=0;
    for(long long int i=n-1;i>=0;i--)
    {
        countb[i]+=prev;
        prev=countb[i];
    }
    long long int finalsum=0;
    for(long long int i=0;i<a.size();i++)
    {
        auto it=upper_bound(b.begin(),b.end(),a[i]);
        long long int index=it-b.begin();
        if(index<countb.size())
        {
            finalsum+=countb[index];
        }
    }   
    cout<<finalsum;
}