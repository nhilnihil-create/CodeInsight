#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector < int > v(n); int mn = 0,mx = 1e9+100;
    for (int x=0;x<n;x++){
        cin>> v[x];
        mn = max(mn, v[x]);
        mx= min(mx,v[x]);
    }

    if (n==2) {
        cout << max(v[0],v[1]) << endl;
        return 0;
    }

    set < int > s;
    for (int x=1;x*x<=mn;x++){
        if (mn%x==0){
            s.insert(x);
            s.insert(mn/x);
        }
    }
    for (int x=1;x*x<mx;x++){
        if (mx%x==0){
            s.insert(x);
            s.insert(mx/x);
        }
    }
    vector < int > ans;
    for (auto it=s.begin();it!=s.end();it++){
        ans.push_back(*it);
    }
    reverse(ans.begin(),ans.end());
    int c=0;
    for (int i=0;i<ans.size();i++){
        c=0;
        for (int x=0;x<n;x++){
            if (v[x]%ans[i]!=0) c++;
            if (c>1) break;
        }
        if (c<2){
            cout << ans[i]<<endl;
        break;
        }
    }
}
