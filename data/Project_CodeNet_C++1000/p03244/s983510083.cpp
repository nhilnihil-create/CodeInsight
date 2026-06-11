#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF=pow(10,9);

int main(){
    int n;
    cin >> n;
    map<int, int> even;
    map<int, int> odd;
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        if(i%2 == 0) even[s]++;
        else odd[s]++;
    }
    int e_first,e_second,e_third,o_first,o_second,o_third;
    vector<pair<int,int>> even_v;
    vector<pair<int,int>> odd_v;
    for(auto p:even){
        auto k = p.first;
        auto v = p.second;
        pair<int,int> q = make_pair(v,k);
        even_v.push_back(q);
    }
    for(auto p:odd){
        auto k = p.first;
        auto v = p.second;
        pair<int,int> q = make_pair(v,k);
        odd_v.push_back(q);
    }
    sort(even_v.begin(), even_v.end());
    reverse(even_v.begin(), even_v.end());
    sort(odd_v.begin(), odd_v.end());
    reverse(odd_v.begin(), odd_v.end());

    if(even_v.at(0).second != odd_v.at(0).second){
        cout << n-even_v.at(0).first-odd_v.at(0).first << endl;
    }
    else{
        cout << n-even_v.at(0).first-max(even_v[1].first,odd_v[1].first) << endl;
    }
}