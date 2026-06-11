#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;
int c[maxn];

void add(int p, int v){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += v;
    }
}

int sum(int p){
    int ret = 0;
    for(int i = p;i > 0; i -= i & -i){
        ret += c[i];
    }
    return ret;
}

string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    int n = s.length();
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'B'){
            add(i + 1, 1);
        }else{
            ans += sum(i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
