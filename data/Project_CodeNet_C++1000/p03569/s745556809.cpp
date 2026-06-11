#include<iostream>
#include<string>
using namespace std;

int main()
{
    string st;
    cin>>st;
    int ans=0;
    int l=0;
    int r=st.size()-1;
    while(l<=r)
    {
        if(st[l]==st[r])
        {
            l++;
            r--;
            continue;
        }
        if(st[l]=='x')
        {
            l++;
            ans++;
            continue;
        }
        if(st[r]=='x')
        {
            r--;
            ans++;
            continue;
        }
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}