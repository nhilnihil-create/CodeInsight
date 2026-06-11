#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(n) long long int n; scanf("%d",&n);
#define mod 10000007
#define N 100001
#define MX 1000000001
#define log(n) (int)log2(n)
#define pb(x) push_back(x);
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define scArr(n) int n; scanf("%d", &n); int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);


int main()
{
    int n, k;
    string s;
    cin>>n>>k>>s;
    s+='2';
    map<pair<int, int> , int> m;
    vector<pair<int, int> > v;
    int in=0, mid=0, det=0;
    int i=0;
    if(s[0]=='0')
    {
        det=1;
        i++;
    }

    for(;i<s.size();i++)
    {
        if(s[i]=='0' && det==0)
        {
            det=1;
        }
        else if(s[i]=='0' && det==1 && s[i-1]!='0')
        {
            m.insert({{in, i-1}, i-in});
            det=0;
            for(i=i-1;i>=0;i--)
            {
                if(s[i]=='0')
                {
                    in=++i;
                    break;
                }
            }
        }
        else if(s[i]=='2')
        {
            m.insert({{in, s.size()-2}, s.size()-1-in});
        }
    }

    for(auto it=m.begin();it!=m.end();it++)
    {
        v.push_back({it->first.first, it->first.second});
    }
    int sum=0, mx;
    for(int i=0;i<k && i<v.size();i++)
    {
//        cout<<v[i].first<<" "<<v[i].second<<endl;
        mx=sum=v[i].second+1;
    }
//    cout<<mx<<endl;
    for(int i=k;i<v.size();i++)
    {
        sum=v[i].second-v[i-k+1].first+1;
        if(sum>mx) mx=sum;
    }
    cout<<mx;
}
