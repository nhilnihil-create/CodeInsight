#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < n;i++)
#define itn int

int main(void){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<int> v(n,0);
    for(int i = 1;i < n;i++){
        if(s.substr(i-1,2) == "AC")v[i]++;
        v[i] += v[i-1];
    }
    
    for(int i = 0;i < q;i++){
        int l,r;
        cin >> l >> r;
        r--;l--;
        cout << v[r]-v[l] << endl;
    }
}