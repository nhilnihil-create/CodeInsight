#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,m,c,l,ans,f1,f2;
    vector<pair<int,int> >v;
    string s;
    cin>>n>>m;
    cin>>s;
    for(i=0;i<n; i++){
        if(s[i]=='0'){ f1=i;j=i;j++;
        while(j<n){if(s[j]=='1') break;
            j++;i++;
        }
        f2=j-1;
        v.push_back(make_pair(f1,f2));
        }
    }
    l=v.size();// cout<<"l "<<l<<endl;
    if(l==0||l<=m){cout<<n<<endl;return 0;}
    ans=v[m].first;
    v.push_back(make_pair(-1,-1));v.push_back(make_pair(n,n));l+=2;
    sort(v.begin(),v.end());
    for(i=2;i<l-m;i++){
        k=v[i+m].first-v[i-1].second-1;
        ans=max(ans,k);
    }
    cout<<ans<<endl;

    //for(i=0;i<v.size();i++) cout<<v[i]<<" ";
}
