#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    map<int, int> m1, m2;  
    for(int i=0; i<n; ++i){
        int x; cin >> x;

        if(i&1)
            ++m1[x];
        else
            ++m2[x];
    }

    pii m1l={0,0}, m2l={0,0};

    for(auto x:m1)
        m1l = max(m1l, {x.second, x.first});
    for(auto x:m2)
        m2l = max(m2l, {x.second, x.first});
    
    if(m1l !=m2l){
        cout << n-m1l.first-m2l.first;
    }
    else{
        int e1=0, e2=0;
        for(auto x:m1)
            if(x.first != m1l.second)
                e1 = max(e1, x.second);

        for(auto x:m2)
            if(x.first != m2l.second)
                e2 = max(e2, x.second);

        if(m1l.first+e2 >= m2l.first+e1){
            cout << n-m1l.first-e2;
        }
        else{
            cout << n-m2l.first-e1;
        }
    }
}
