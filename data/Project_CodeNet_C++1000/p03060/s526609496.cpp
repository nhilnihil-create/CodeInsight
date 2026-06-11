    #include <bits/stdc++.h>
    using namespace std;

int main()
{              //coded by shoaib ////

    long long int n;
    cin>>n;
    long long int i;
    vector<long long int >v(n),c(n),z;
    for(i=0; i<n; i++)
        cin>>v[i];
    for(i=0; i<n; i++)
        cin>>c[i];
    for(i=0; i<n; i++)
    {
        z.push_back(v[i]-c[i]);
    }
    sort(z.begin(),z.end());
    long long int ans=0;
    for(long long int i=n-1; i>=0; i--)
    {
        if(z[i]<0)
            break;
        ans+=z[i];
    }
    cout<<ans<<endl;
}
