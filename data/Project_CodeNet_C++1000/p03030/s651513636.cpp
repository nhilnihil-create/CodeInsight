#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <tuple <string , int ,int> > sp(0);
    rep(i,n){
        string s;
        int p;
        cin >> s >> p;
        tuple <string , int , int> spi (s,-p,i+1);
        sp.push_back(spi);
    }
    sort(all(sp));
    rep(i,n){
        cout << (get <2> (sp[i]))<< endl;
    }
}
