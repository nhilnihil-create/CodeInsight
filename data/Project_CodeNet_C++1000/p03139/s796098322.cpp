#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    int c=0;
    cin >> n >> a >> b;
    if (n > a+b) c = 0;
    else c = a+b-n;
    cout << min(a,b) << ' ' << c << '\n';
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}