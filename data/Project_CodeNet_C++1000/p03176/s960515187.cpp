#include<bits/stdc++.h>
using namespace std;
vector<long long> tree(1e6,0);

long long getit(int ss,int se, int p, int l, int r){
    if(ss > se || ss > r || se < l)
        return (long long)0;
    if(l<= ss && se <= r)
        return tree[p];
    int mid = (ss+se)/2;
    return max(getit(ss,mid, 2*p, l, r), getit(mid+1,se, 2*p + 1,l,r));
}

void update(int ss,int se, int p, int l, long long val){
    if(ss > se)
        return ;
    if(ss == se)
    {
        tree[p] += val;
        return;
    }
    int mid = (ss+se)/2;
    if(l > mid)
        update(mid+1,se, 2*p+1 , l, val);
    else update(ss, mid, 2*p, l, val);
    tree[p] = max(tree[2*p],tree[2*p+1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    std::vector<int> h(n), bb(n);
    for(auto &x : h)
        cin>>x;
    for(auto &x : bb)
        cin>>x;
    long long ans = 0;
   for(int a= 0; a<n;a++){
        int l = h[a];
       
        long long tt = getit(1,n,1,1,l);
       // cout<<tt<<" "<<l<<endl;
        update(1,n,1,l,bb[a] + tt);
        ans = max(ans,(long long)bb[a]+(long long)tt);
   }
    cout<<ans<<endl;
    return 0;
}
