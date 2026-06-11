#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    int k; cin >> k;
    vector<string> vec;
    for(int i = 0; i < s.size(); ++i){
        for(int j = 1; j <= k; ++j){
            string tmp = s.substr(i,j);//初め,文字数
            vec.push_back(tmp);
        }
    }
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)),vec.end());
    cout << vec[k-1] << endl;
    return 0;
}