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
    int r, d, x;
    cin >> r >> d >> x;
    for(int i=1; i<=10; i++){
        x = r*x - d;
        cout << x <<"\n";
    }
}
