#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    string s;cin >> s;s = " " + s;
    int n = s.size() - 1;
    for(int i = 1 ; i < n ; ++i){
        if(s[i] != s[n - i])return cout << -1 , 0;
    }
    if(s[1] == '0' || s[n] == '1')return cout << -1 , 0;
    int pre = 1;
    for(int i = 2 ; i <= n ; ++i){
        if(s[i] == '1'){
            for(int j = pre ; j < i ; ++j)cout << i << " " << j << endl;
            pre = i;
        }
    }
    cout << n - 1 << " " << n << endl;
}

