#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> city(m);
    vector<vector<int>> a(n);
    for (int i=0;i<m;i++){
        int p,y;
        cin >> p >> y;
        city[i].first = p;
        city[i].second = y;
        a[p-1].push_back(y);
    }
    for (int i=0;i<a.size();i++){
        sort(a[i].begin(),a[i].end());
    }
    for (int i=0;i<m;i++){
        int now_f = city[i].first-1; //探す場所
        int now_s = city[i].second; //探したいもの
        auto Iter1 = upper_bound(a[now_f].begin(),a[now_f].end(),now_s);
        city[i].second = Iter1 - a[now_f].begin();
        // for(int j=0;j<a[city[i].first-1].size();j++){
        //     //ここを2分にする?
        //     if(city[i].second==a[city[i].first-1][j]){
        //         city[i].second = j+1;
        //     }
        // }
    }
    //6桁にする
    vector<string> ans(m);
    for(int i=0;i<m;i++){
        ans[i] = "000000000000";
        int at = city[i].first;
        string s_at = to_string(at);
        int year = city[i].second;
        string s_year = to_string(year);
        ans[i].replace(6-s_at.size(),s_at.size(),s_at);
        ans[i].replace(12-s_year.size(),s_year.size(),s_year);
        cout << ans[i] << endl;;
    }

    return 0;
}