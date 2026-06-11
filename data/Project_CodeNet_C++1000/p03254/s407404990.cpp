#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    int n,x;

    cin>>n>>x;
    vector<int>a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a.at(i);
    }

    sort(a.begin(),a.end());
    int flag=0;
    for(int i=0;i<n;i++)
    {
        x=x-a.at(i);

        if(x<0)
        {
          break;
        }
        flag++;

    }

    if(x>0)
    {
        flag--;
    //cout<<" "<<flag<<endl;
    }
    cout<<flag<<endl;
    return 0;

}
