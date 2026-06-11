#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        if(i == k-1){
            s[i] = char(s[i] - 'A' + 'a');
        }
    }
    cout << s;
}
