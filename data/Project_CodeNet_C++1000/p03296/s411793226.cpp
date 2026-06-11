#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int mod = 998244353;
const ll inf = 3e18 + 5;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }  

const int n = 1e9;

int main(){
    int n;
    cin >> n;
    vi a(n);
    vi b;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i>0){
            if(a[i] == a[i-1])
                cnt++;
            else{
                b.push_back(cnt);        
                cnt=1;
            }
        }
    }
    b.push_back(cnt);
    int sol = 0;
    for(int x : b){
        sol+=x/2;
    }
    cout << sol;
}