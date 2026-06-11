#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int n;
long long mod = 1000000007;
long long tree[400005];
int pre[200005];

void update(int i, int v){
    i += n;
    while(i > 0){
        tree[i] += v;
        tree[i] %= mod;
        i >>= 1;
    }
}

long long query(int l, int r){
    long long ans = 0ll;
    for(l += n, r += n;l < r;l >>= 1, r >>= 1){
        if(l&1){
            ans += tree[l];
            ans %= mod;
            l++;
        }
        if(r&1){
            r--;
            ans += tree[r];
            ans %= mod;
        }
    }
    return ans;
}

int main()
{
    //freopen("i.txt","r",stdin);

    ios_base::sync_with_stdio(false);


    cin >> n;
    int arr[n];
    fill(pre,pre+200005,-1);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        arr[i]--;
    }
    vector<ii> stuff;
    for(int i = 0;i < n;i++){
        int x = arr[i];
        if(pre[x] == -1){
            pre[x] = i;
        }
        else{
            if(pre[x] != i - 1) stuff.push_back(ii(pre[x],i));
            pre[x] = i;
        }
    }



    long long ans = 1ll;
    update(0,1);

    sort(stuff.begin(),stuff.end());

    for(int i = 0;i < stuff.size();i++){
        int x = stuff[i].first;
        int y = stuff[i].second;
        long long ways = query(0,x+1);
        ans += ways;
        ans %= mod;

        update(y,ways);
    }

    cout << ans;
    return 0;
}
