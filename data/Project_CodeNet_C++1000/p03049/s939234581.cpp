#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

int countAB(string s){
    int ret = 0;
    reps(i,1,s.size()-1){
        if(s[i-1]=='A'&&s[i]=='B'){
            ret++;
            i++;
        }
    }
    return ret;
}

int main(){
    int N; cin >> N;
    vector<string> s(N);
    collect(s, N);
    int res = 0;
    int a = 0, b = 0, ba = 0;
    rep(i,N){
        res += countAB(s[i]);
        bool has_A = *(s[i].end()-1)=='A';
        bool has_B = *(s[i].begin())=='B';
        if(has_A && has_B){
            ba++;
            continue;
        }
        if(has_A) a++;
        if(has_B) b++;
    }
    
    if(ba>0){
        res += ba - 1;
        if(a > 0){
            res++; a--;
        }
        if(b > 0){
            res++; b--;
        }
    }
    res += min(a,b);
    
    cout << res << endl;
}