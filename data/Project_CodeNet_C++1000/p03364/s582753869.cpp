#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
#define vii vector <pair <int, int> >
using namespace std;

ll n, ans;
string s[306];


int main(){

cin >> n;

for(int i = 1; i <= n; ++i) {

    cin >> s[i];

}

for(int k = 0; k < n; ++k) {

    bool lol = 0;

    for(int i = 1; i <= n; ++i) {

        for(int j = 0; j < n; ++j) {

            ll A = (j + k) % n + 1;
            ll B = i - 1;

            ll ka = A;
            ll kb = (B - k);

            if(kb < 0) {kb += n;}

            if(s[i][j] != s[A][kb]) {lol = 1;}

        }

    }


    if(!lol) {ans++;}

}

cout << (ans * n * 1ll);

return 0;
}
