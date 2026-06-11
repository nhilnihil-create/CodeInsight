#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int t , p;
string s[MAXX];
int n[MAXX];
int x[MAXX];

int main()
{
    _FastIO;
    cin >> t >> p;
    vector<pair<int , int> > v[MAXX];
    for(int i = 0; i < p; i++){
        cin >> n[i] >> x[i];
        v[n[i]].push_back({x[i] , i});
    }
    vector<pair<int , int> > path[MAXX];
    for(int k = 0; k <= 100000; k++){
        sort(v[k].begin() , v[k].end());
      for(int i = 0; i < v[k].size(); i++){
        path[k].push_back({v[k][i].second , i + 1});
    }
    sort(path[k].begin() , path[k].end());
    }
    vector<int> used(100005 , 0);
    for(int i = 0; i < p; i++){
        int y = n[i];
        string h = "";
        while(y > 0){
            int tp = y % 10;
            h += char(tp + 48);
            y /= 10;
        }
        reverse(h.begin() , h.end());
        while(h.size() < 6){
            h = '0' + h;
        }
        cout << h;
        int m = path[n[i]][used[n[i]]].second;
        h = "";
        while(m > 0){
            int tp = m % 10;
            h += char(tp + 48);
            m /= 10;
        }
        reverse(h.begin() , h.end());
        while(h.size() < 6){
            h = '0' + h;
        }
        cout << h << endl;
        used[n[i]]++;
        }
        return 0;
    }
