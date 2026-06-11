#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i] = abs(a[i]-x);
    }
    sort(a.begin(),a.end());
    int e = a.front();
    vector<int> s;
    for(int i=1; i*i<=e; i++){
        if(e%i==0){
            s.push_back(i);
            s.push_back(e/i);
        }
    }
    for(int i=1; i<n; i++){
        vector<int> f;
        for(int j=0; j<(int)s.size(); j++){
            if(a[i]%s[j]==0){
                f.push_back(s[j]);
            }
        }
        s = f;
    }
    sort(s.begin(),s.end(),greater<int>());
    cout << s.front() << endl;
    

    return 0;
}