#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846

    int n,m;
    int sz[100005];
    int parent[100005];
    int ranking[100005];
    vector<pair<int,int>>a(100005);

    int find_comp(int x){
        if(x!=parent[x]){
            parent[x]=find_comp(parent[x]);
        }
        return parent[x];
    }

    bool same_comp(int x, int y){
        return find_comp(x)==find_comp(y);
    }

    void join_comp(int X,int Y){
        int x=find_comp(X);
        int y=find_comp(Y);
        if(ranking[x]>ranking[y]){
            parent[y]=x;
            sz[x]+=sz[y];
        }
        else{
            parent[x]=y;
            sz[y]+=sz[x];
            if(ranking[x]==ranking[y])
                ranking[y]++;
        }
    }



    void solve(){
        cin>>n>>m;
        vector<long long>ans(m+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            sz[i]=1;
            ranking[i]=0;
        }
        for(int i=0;i<m;i++){
            cin>>a[i].first>>a[i].second;
            a[i].first--;
            a[i].second--;
        }
        ans[m]=(ll)n*(n-1)/2;
        for(int i=m-1;i>=0;i--){
            int x=a[i].first;
            int y=a[i].second;
            if(same_comp(x,y)){
                ans[i]=ans[i+1];
                continue;
            }
            ll size_x=sz[find_comp(x)];
            ll size_y=sz[find_comp(y)];
            join_comp(x,y);
            ans[i]=max(ans[i+1]-size_x*size_y,0LL);
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
