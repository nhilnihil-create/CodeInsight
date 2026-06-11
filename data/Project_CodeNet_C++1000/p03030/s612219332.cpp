#include <bits/stdc++.h>
using namespace std;
struct tpl {
    string s;
    int x,ind;
};
bool comp(tpl a,tpl b) {
    if (a.s==b.s) return a.x>b.x;
    return a.s<b.s;
}
int main() {
    int n,x;
    cin>>n;
    vector<tpl> v;
    string str;
    for (int i=0; i<n; i++) {
        cin>>str>>x;
        v.push_back({str,x,i});
    }
    sort(v.begin(),v.end(),comp);
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].ind+1<<'\n';
    }
}