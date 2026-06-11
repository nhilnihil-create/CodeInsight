#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b;
    cin >> n >> m;
    vector<tuple<int,int,int>> c;
    vector<int> count(n + 1,1);
    vector<pair<int,int>> ans(m);
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        c.emplace_back(a,b,i);
    }
    sort(c.begin(),c.end());
    for(int i = 0;i < m;i++){
        ans[get<2>(c[i])].first = get<0>(c[i]);
        ans[get<2>(c[i])].second = count[get<0>(c[i])];
        count[get<0>(c[i])]++;
    }
    for(int i = 0;i < m;i++){
        cout << setfill('0') << right << setw(6) << ans[i].first;
        cout << setfill('0') << right << setw(6) << ans[i].second << endl;
    }

}

