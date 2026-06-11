#include <bits/stdc++.h>
using namespace std;
int n,arr[200001];
int ans=1987654321;

vector <pair<int,int> > before;

bool f(int x)
{
    before.clear();
    if(x==0) return false;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]<arr[i]) continue;
        while(!before.empty() && before.back().first>=arr[i]) before.pop_back();
        for(int j = arr[i]-1 ; ; j--)
        {
            if(j<0) return false;
            if(before.empty())
            {
                if(x==1) return false;
                before.push_back({j,1});
                break;
            }
            pair <int,int> t = before.back();
            before.pop_back();
            if(t.first == j)
            {
                if(t.second+1>=x) continue;
                t.second++;
                before.push_back(t);
            }
            else
            {
                before.push_back(t);
                if(x==1) return false;
                before.push_back({j,1});
            }
            break;
        }
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int s=1,e=n;
    for(s=1,e=n;s<=e;)
    {
        int m=(s+e)/2;
        if(f(m)) ans=m,e=m-1;
        else s=m+1;
    }
    if(f(ans-1)) printf("%d",ans-1);
    else if(f(ans)) printf("%d",ans);
    else if(f(ans+1)) printf("%d",ans+1);
}
