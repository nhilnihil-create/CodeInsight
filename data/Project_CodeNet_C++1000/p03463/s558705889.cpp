#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()

using namespace std;

ll n,m,k,y,cnt;
string s;
vector <int> v;
pair <int, int> p[100005];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    y =  k - (m - 1);
    if (y % 2 == 0){
        cout << "Borys";
    }
    else {
        cout << "Alice";
    }
}
