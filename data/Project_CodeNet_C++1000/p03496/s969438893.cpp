#include <bits/stdc++.h>

using namespace std;

long long niz[61];
vector<pair<int,int> >potez;

int poz(int x,int n)
{
    for(int i=0;i<=n;i++)
        if(niz[i]==x)return i;
    return -1;
}

bool neopadajuci(int n)
{
    for(int i=1;i<n;i++)
    {
        if(niz[i+1]<niz[i])return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
   // int maxi=INT_MIN;
  //  int mini=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>niz[i];
       // if(niz[i]>maxi)maxi=niz[i];
      //  if(niz[i]<mini)mini=niz[i];
    }
    if(neopadajuci(n))
    {
        cout<<0;
        return 0;
    }
    long long mini=*min_element(niz,niz+n+1);
    long long maxi=*max_element(niz,niz+n+1);
    if(abs(mini)>abs(maxi))
    {
        int p=poz(mini,n);
        for(int i=1;i<=n;i++)
        {
            if(i==p)continue;
            niz[i]+=mini;
            potez.push_back(make_pair(p,i));
        }
        for(int i=n-1;i>=1;i--)
        {
            niz[i]+=niz[i+1];
            potez.push_back(make_pair(i+1,i));
        }
    }
    else
    {
        int p=poz(maxi,n);
        for(int i=1;i<=n;i++)
        {
            if(i==p)continue;
            niz[i]+=maxi;
            potez.push_back(make_pair(p,i));
        }
        for(int i=2;i<=n;i++)
        {
             niz[i]+=niz[i-1];
             potez.push_back(make_pair(i-1,i));
        }
    }
    cout<<potez.size()<<endl;
    for(int i=0;i<potez.size();i++)
        cout<<potez[i].first<<" "<<potez[i].second<<endl;
  // for(int i=1;i<=n;i++)
  //     cout<<niz[i]<<" ";
    return 0;
}
