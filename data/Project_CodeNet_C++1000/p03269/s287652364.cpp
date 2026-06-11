#include<bits/stdc++.h>
using namespace std;
int main(){
    int l;
    cin >> l;
    vector<int>v;
    for(int i = 0; i <= 22; i++){
        if(l & (1 << i)){
            v.push_back(i);
        }
    }
    reverse(v.begin(), v.end());
    int p = v.size();
    vector<int>val(p + 3);
    val[0] = 1 << v[0];
    for(int i = 1; i < p; i++){
        val[i] = val[i - 1] + (1 << v[i]);
    }
    vector<pair<pair<int, int>, int> >edgelist;
    for(int i = 2; i <= v[0] + 1; i++){
        edgelist.push_back(make_pair(make_pair(i - 1, i), (1 << (i - 2))));
        edgelist.push_back(make_pair(make_pair(i - 1, i), 0));
    }
    for(int i = 1; i < p; i++){
        edgelist.push_back(make_pair(make_pair(v[i] + 1, v[0] + 1), val[i - 1]));
    }
    cout << v[0] + 1 << ' ' << edgelist.size() << '\n';
    for(int i = 0; i < edgelist.size(); i++){
        cout << edgelist[i].first.first << ' ' << edgelist[i].first.second << ' ' << edgelist[i].second << '\n';
    }
    return 0;
}