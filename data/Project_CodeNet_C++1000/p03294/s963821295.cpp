#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++)
    {   long long k;
        cin>>k;
        s+=k;
    }
    cout<<s-n<<endl;

    return 0;

}
