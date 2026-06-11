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
    cout << fixed << setprecision(6);
    int n;
    long double aux, cnt = 0, rta = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> aux >> s;
        if(s == "JPY") rta += aux;
        else cnt += aux;
    }
    rta += cnt*380000;
    cout << rta << endl;
    return 0;
}

