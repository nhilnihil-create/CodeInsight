#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    map<ll, int> problems;
    for(int i=0; i<n; i++){
        ll d; cin>>d;
        if(problems.count(d)){
            problems[d]++;
        }
        else problems[d] = 1;
    }
    int m; cin>>m;
    for(int i=0; i<m; i++){
        ll t; cin>>t;
        if(problems.count(t) && (problems[t]>=1)) problems[t]--;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}