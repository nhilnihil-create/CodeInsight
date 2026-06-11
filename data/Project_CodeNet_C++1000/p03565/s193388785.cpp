#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
// int A[N];

void sol(){
    string s ,t ; cin >> s >> t ;
    int n = s.length() , m = t.length();

    for(int i = n-m; i >=0  ; --i){
        string a = s;
        bool ok = 1;
        for(int j = 0 ; j < m ; ++j){
            if(!(s[i+j]==t[j] || s[i+j]=='?')){ok = 0;break;}
            a[i+j] = t[j];
        }
        if(ok){
            for(int ii = 0; ii < n ; ++ii){
                if(a[ii]=='?') cout << 'a';
                else cout << a[ii] ;
            }
            cout << endl;
            return;
        }
    }

    
    cout << "UNRESTORABLE" << endl;
}

int32_t main(){
    fast;
    int t = 1; 
    // cin >> t; 
    while(t--) sol();    
    return 0;
}