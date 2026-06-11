#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
T gcd(T a, T b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int T;
    cin >> T;
    vector<bool> ans(T);
    for(int i=0; i<T; i++){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;

        if(A<B){ans[i] = false; continue;}
        if(B>D){ans[i] = false; continue;}
        if(B-1<=C){ans[i] = true; continue;}

        ll u = (C+1-A>=0) ? (C+1-A)%B : B-(-(C+1-A)%B);
        ll v = (B-1-A>=0) ? (B-1-A)%B : B-(-(B-1-A)%B);
        D %= B;
        ll d = gcd(B, D);
        if(u<=v && u%d!=0 && u/d == v/d){ans[i] = true; continue;}
        // if(u>v && v<d && B-d<u){ans[i] = true; continue;}
        ans[i] = false;
    }

    for(int i=0; i<T; i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}