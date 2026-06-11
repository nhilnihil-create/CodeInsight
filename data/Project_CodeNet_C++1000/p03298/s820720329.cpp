#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<string,string>,int>p;
map<pair<string,string>,int>q;
map<int,pair<string,string> >rec;
ll ans;
int main()
{
    int n;
    cin>>n;
    char pi[40];
    string t1;
    string t2;
    //string t3,t4;
    cin>>pi;
    for(int i=0; i<n; i++)
    {
        t1=t1+pi[i];
    }
    int k=0;
    for(int i=2*n-1; i>=n; i--)
    {
        t2=t2+pi[i];
    }
    k=0;
    //cout<<pi<<" "<<t1<<" "<<t2<<endl;
    int po=pow(2,n);
    for(int i=0; i<po; i++)
    {
        string m1;
        string m2;
        int k1=0,k2=0;
        int wer=i;
        for(int j=0; j<n; j++)
        {
            if(wer%2==0)
            {
                m1=m1+t1[j];
            }
            else
            {
                m2=m2+t1[j];
            }
            wer/=2;
        }
        p[make_pair(m1,m2)]++;
        if(p[make_pair(m1,m2)]==1)
        {
            rec[k++]=make_pair(m1,m2);
            //cout<<k<<" "<<m1<<" "<<m2<<endl;
        }
    }
    for(int i=0; i<po; i++)
    {
        string m1;
        string m2;
        int k1=0,k2=0;
        int wer=i;
        for(int j=0; j<n; j++)
        {
            if(wer%2==0)
            {
                m1=m1+t2[j];
            }
            else
            {
                m2=m2+t2[j];
            }
            wer/=2;
        }
        q[make_pair(m1,m2)]++;
    }
    string tr,te;
    for(int i=0;i<k;i++)
    {
       tr=rec[i].first;
       te=rec[i].second;
       //cout<<tr<<" "<<te<<p[make_pair(tr,te)]<<" "<<q[make_pair(te,tr)]<<endl;
       ans+=(ll)p[make_pair(tr,te)]*(ll)q[make_pair(te,tr)];
    }
    cout<<ans<<endl;
    return 0;
}
