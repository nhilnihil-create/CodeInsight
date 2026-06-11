#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
void chmin(int &a, int b) {if(a > b) a = b;}

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool palindrome(string s){
    bool flag = true;
    rep(i,0,s.length()/2){
        if(s[i] != s[s.length() - i]) flag = false;
    }
    return flag;
}


int main(){
    string s;
    cin >> s;
    int nx = 0;
    int i = 0;
    int j = s.length()-1;
    while(i != j){
        if(s[i] == s[j]){
            if(i == j-1)break;
            i++;j--;
        }else if(s[i] == 'x'){
            i++;nx++;
        }else if(s[j] == 'x'){
            j--;nx++;
        }else{
            cout << -1;
            return 0;
        }
    }
    cout << nx;
    
}