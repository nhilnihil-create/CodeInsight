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

bool cmp(const pair<pair<string,int>,int> &a, pair<pair<string,int>,int> &b){
    if(a.ft.ft == b.ft.ft){
        return a.ft.sd > b.ft.sd;
    }
    else return a.ft.ft < b.ft.ft;
}

int main() {
    fastIO;
    int n, aux;
    string s;
    vector<pair<pair<string,int>,int>> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> aux;
        lista.pb({{s,aux},i+1});
    }
    sort(lista.begin(), lista.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << lista[i].sd << endl;
    }
    return 0;
}

