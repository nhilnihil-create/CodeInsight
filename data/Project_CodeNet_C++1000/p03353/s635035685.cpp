#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int k;
    cin>>k;
    int n = sz(s);
    set<string> se;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            string t = s.substr(j , i);
            se.insert(t);
        }
    }
    for(int i = 1; i < k; i++){
        se.erase(*se.begin());
    }
    string ans = *se.begin();
    cout<<ans;

}