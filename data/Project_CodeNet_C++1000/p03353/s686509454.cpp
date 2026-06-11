#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    string s; int k; cin >> s >> k; int n = s.size();
    vector<string> v;
    rep(i, n){
        repn(j, k){
            if(i + j > n) continue;
            string t = s.substr(i, j);
            v.push_back(t);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    cout << v[k-1] << endl;
}