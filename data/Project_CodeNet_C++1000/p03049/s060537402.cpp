#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vector<string> s(N);
    for(int i=0; i<N; i++){
        cin >> s[i];
    }
    ll c = 0;
    ll a = 0;
    ll b = 0;
    ll d = 0;
    for(int i=0; i<N; i++){
        ll l = s[i].size();
        for(int j=0; j<l-1; j++){
            if(s[i][j] == 'A'&&s[i][j+1] == 'B'){
                c++;
            }
        }
        if(s[i][0] == 'B'){
            b++;
        }
        if(s[i][l-1] == 'A'){
            a++;
        }
        if(s[i][0] == 'B'&&s[i][l-1] == 'A'){
            d++;
        }
    }
    c += min(a, b);
    if(d == a&&d == b&&d!=0){
        c--;
    }
    cout << c;
}