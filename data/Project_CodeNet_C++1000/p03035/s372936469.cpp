#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];
int n, m;
vector<int>adj[e];
bool vs[e];

//beginner 1999 127

int main()
{
    int a, b;
    cin >> a >> b;
    if(a >= 13){
        cout << b;
        return 0;
    }
    if(a >= 6 && a <= 12){
        cout << b/2;
        return 0;
    }
    if(a <= 5){
        cout << 0;
        return 0;
    }
}
