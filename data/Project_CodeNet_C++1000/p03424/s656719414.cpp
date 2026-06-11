#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    vector <char> s(n);
    for(int i=0;i<n;i++)
    {

        cin>>s[i];

    }
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        if(s[i]!=s[i+1])
            cnt++;
    }
    if(cnt==3)
    cout<<"Three"<<endl;
    else
        cout<<"Four"<<endl;
}
