#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,s=0;
    cin>>N;
    int a[N+5];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        while(a[i]%2==0) {a[i]/=2; s++;}
    }
    cout<<s<<endl;
    return 0;
}
