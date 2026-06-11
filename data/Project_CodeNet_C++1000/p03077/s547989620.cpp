#include <bits/stdc++.h>
using namespace std ;
#define data_type long long
#define endl "\n"
int main()
{
    data_type t,n,m,b,c,d,k,i,a=-1,te=0;
    cin>>n;
    vector<data_type>vc(5);
    for(auto &i:vc)
        cin>>i;
    for(int i=0; i<5; i++)
        {
            if(i==0)
                vc[i]=(n+vc[i]-1)/vc[i]+i;
            else
                vc[i]=max(vc[i-1]+1,(n+vc[i]-1)/vc[i]+i);
        }

    cout<<vc.back()<<endl;

    return 0;
}

