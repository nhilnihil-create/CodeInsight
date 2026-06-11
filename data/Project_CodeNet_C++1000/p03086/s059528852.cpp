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
    string s;
    int lim, rta = 0, aux = 0;
    cin >> s;
    lim = s.size();
    for(int i = 0; i < lim; i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            aux++;
        }
        else aux = 0;
        rta = max(rta, aux);
    }
    cout << rta << endl;
    return 0;
}

