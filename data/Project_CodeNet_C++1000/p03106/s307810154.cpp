#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    int a, b, k, lim, ind;
    vector<int> div;
    cin >> a >> b >> k;
    lim = min(a, b);
    for(int i = 1; i <= lim; i++){
        if(a%i == 0 && b%i == 0){
            div.pb(i);
        }
    }
    sort(div.begin(), div.end());
    ind = div.size() - k;
    cout << div[ind] << endl;
    return 0;
}

