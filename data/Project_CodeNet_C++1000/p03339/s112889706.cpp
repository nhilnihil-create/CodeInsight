#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    string s; cin >> s;
    vector<int> east(n,0), west(n,0), cnt(n, 0);
    for (int i = 0; i < n-1; i++){
        if (s[i] == 'E') east[i+1] = east[i] + 1;
        else east[i+1] = east[i];
    }
    for (int i = n-1; i > 0; i--){
        if (s[i] == 'W') west[i-1] = west[i] + 1;
        else west[i-1] = west[i];
    }
    for (int i = 0; i < n; i++) cnt[i] = east[i] + west[i];
    sort(cnt.begin(), cnt.end());
    cout << n - *(cnt.end()-1) - 1 << endl;
    return 0;
}