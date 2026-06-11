#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5e5 + 5;
multiset<int,greater<int>> s[maxn];
int n , a[maxn];

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n;
    for(int i = 0 ; i < (1 << n) ; ++i){
        cin >> a[i];
        s[i].insert(a[i]);
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < (1 << n) ; ++j){
            if((j >> i) & 1){
                for(int c : s[j ^ (1 << i)]){
                    s[j].insert(c);
                }
                while(s[j].size() > 2)s[j].erase(s[j].find(*s[j].rbegin()));
            }
        }
    }
    int res = 0;
    for(int i = 1 ; i < (1 << n) ; ++i){
        res = max(res , *s[i].begin() + (*++s[i].begin()));
        cout << res << '\n';
    }
}

