#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int x, y; cin>>x>>y;
    vector<int> a;
    for(int i=0; i<s.size(); ) {
        int c=0;
        for(; i<s.size() && s[i]=='F'; ++i) ++c;
        a.push_back(c);
        if (!c) ++i;
    }
    if (a[0]>0) { x-=a[0]; a.erase(a.begin()); }

    vector<int> tx, ty;
    for(int i=0, c=1; i<a.size(); ++i) {
        if (!a[i]) c=!c;
        (c ? tx : ty).push_back(a[i]);
    }

    auto f=[](auto& t, int g) {
        set<int> s={0};
        for(auto& d: t) if (d) {
            set<int> n;
            for(auto& k: s) n.insert({k-d, k+d});
            s=n;
        }
        return s.count(g);
    };

    cout<<(f(tx, x) && f(ty, y) ? "Yes" : "No")<<endl;
}