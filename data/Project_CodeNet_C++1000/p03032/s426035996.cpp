#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int max_value(vector<int> &d, int i, int n, int l){
    int ans=0;
    for(int j=0; j<=i; j++){
        //左からj回取り出す
        int get_v=0;
        vector<int> a;
        vector<int>check(n,0);
        for(int k=0; k<j; k++){
            int g = d.at(k);
            get_v+=g;
            a.push_back(g);
            check.at(k) = 1;
            if(k==n-1) break;
        }
        for(int k=0; k<i-j; k++){
            int g=d.at(n-1-k);
            if(check.at(n-1-k) == 1) break;
            get_v+=g;
            a.push_back(g);
            if(k == n-1) break;
        }
        sort(a.begin(), a.end());
        int m=a.size();
        int cnt=0;
        while(cnt<l-i && cnt<m){
            if(a.at(cnt) > 0) break;
            get_v -= a.at(cnt);
            cnt++;
        }
        ans = max(ans, get_v);
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> d;
    for(int i=0; i<n;i++){
        int v;
        cin >> v;
        d.push_back(v);
    }
    int ans=0;
    for(int i=0; i<=k; i++){
        //i回取り出す
        int count=max_value(d, i, n, k);
        ans = max(ans, count);
        //cout << i<< ' '<< count << endl;
    }
    cout << ans << endl;
}
