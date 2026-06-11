#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int h, w, n;
string t, s;
int si, sj;

bool inr(int ci, int cj){
    if(ci >= 1 && cj >= 1 && ci <= h && cj <= w)
        return true;
    return false;
}

bool whoWins(char d1, char d2){
    int ci = si;
    int cj = sj;
    for(int i = 0 ; i < n; i ++ ){
        if(t[i] == d1){
            if(d1 == 'U')ci--;
            else if(d1 == 'D') ci++;
            else if(d1 == 'L') cj -- ;
            else if(d1 == 'R') cj ++ ;
            if(!inr(ci, cj))
                return true;
        }
        if(s[i] == d2){
            if(d2 == 'U'){
                if(inr(ci-1, cj)) ci -- ;
            }
            else if(d2 == 'D'){
                if(inr(ci+1, cj)) ci ++ ;
            }
            else if(d2 == 'L'){
                if(inr(ci, cj-1)) cj -- ;
            }
            else if(d2 == 'R'){
                if(inr(ci, cj+1)) cj ++ ;
            }
        }
    }
    return false;
}

int main(){
    fastIO;
    cin >> h >> w >> n;
    cin >> si >> sj;
    cin >> t >> s;  
    if(whoWins('R', 'L') || whoWins('L', 'R') || whoWins('U', 'D') || whoWins('D', 'U')){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
    return 0;
}

