#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
int a[100005],b[100005];
long long int c[100005];
int n,m;
vector<int> sima[100005];
int num;
long long int dfs(int now){
        if(mp[a[now]]+mp[b[now]]==0){
            mp[a[now]]=num;
            mp[b[now]]=num;
            sima[num].push_back(a[now]);
            sima[num].push_back(b[now]);
            num++;
            return c[now]+1LL;
        }
        else if(mp[a[now]]==0 || mp[b[now]]==0){
            if(mp[a[now]]==0 && mp[b[now]]>0){
                mp[a[now]]=mp[b[now]];
                sima[mp[b[now]]].push_back(a[now]);
                long long int tmp=sima[mp[b[now]]].size();
                return c[now]+tmp-1;
            }
            else{
                mp[b[now]]=mp[a[now]];
                sima[mp[a[now]]].push_back(b[now]);
                long long int tmp=sima[mp[a[now]]].size();
                return c[now]+tmp-1;
            }
        }
        else if(mp[a[now]]==mp[b[now]])return c[now];
        else{
            long long int tmp=sima[max(mp[a[now]],mp[b[now]])].size();
            long long int tmp2=sima[min(mp[a[now]],mp[b[now]])].size();
            for(int u:sima[max(mp[a[now]],mp[b[now]])]){
                mp[u]=min(mp[a[now]],mp[b[now]]);
                sima[min(mp[a[now]],mp[b[now]])].push_back(u);                
            }
            return c[now]+tmp*tmp2;       
        }
        }

int main(){
    cin >> n >> m;
    for(int i=1;i<m+1;i++)cin >> a[i] >> b[i];
    num=1;
    for(int i=m;i>0;i--)c[i-1]=dfs(i);
    for(int i=1;i<m+1;i++)cout << c[0]-c[i] << endl;
}