#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, tmp;cin >>n;
    pair<pair<string,int>,int> cc[n];
    fo(i,n){
        cin >> cc[i].first.first ;
        cin >>tmp;
        cc[i].first.second = -tmp;
        cc[i].second = i+1;
    }
    sort(cc, cc+n);
    fo(i,n){
        cout << cc[i].second << "\n";
    }
}
