#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll X,Y;
    cin>>X>>Y;
    ll counter=1;
    for(int i=0; ; i++) {
        if(X>Y) break;
        X+=X;
        //cout<<X<<endl;
        counter++;
    }
    cout<<counter-1<<endl;
}