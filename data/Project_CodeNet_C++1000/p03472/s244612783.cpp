#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool cmp(pair<int,int> l,pair<int,int> r)
{
    if(l.first<r.first)
        return 1;
    if(l.first>r.first)
        return 0;
    if(l.second>r.second)
        return 1;
    return 0;
}

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> >v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v),cmp);
    vector<int>cur;
    for(int i=0; i<n-1; i++)
        cur.push_back(v[i].second);
    sort(all(cur));

    int it=n-2,att=v[n-1].first,rev_sum=0,cnt=0;
    int need=m/att;
    if(m%att)
        need++;
    while(it>=0)
    {
        cnt++;
        rev_sum+=cur[it--];
        int temp_m=m-rev_sum;
        temp_m=max(temp_m,0);
        int t_need=temp_m/att;
        if(temp_m%att)
            t_need++;
        need=min(need,t_need+cnt);

        cnt++;
        rev_sum+=v[n-1].second;
        temp_m=m-rev_sum;
        temp_m=max(temp_m,0);
        t_need=temp_m/att;
        if(temp_m%att)
            t_need++;
        need=min(need,t_need+cnt);

        cnt--;
        rev_sum-=v[n-1].second;



    }
    int t=m-v[n-1].second;
    t=max(t,0);
    int t2=t/att;
    if(t%att)
        t2++;
    need=min(need,t2+1);
    cout<<need<<endl;

    return 0;
}
