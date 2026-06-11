#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;




int main(){
    int h,w,n;cin >> h >> w >> n;
    int sr,sc;cin >> sr >> sc;
    string s,t;cin >> s >> t;
    int l = 0, r = w + 1;
    for (int i = n-1; i >= 0; i--) {
        if(t[i] == 'L') r = min(r+1,w+1);
        else if(t[i] == 'R') l = max(0,l-1);
        if(s[i] == 'R') r--;
        else if(s[i] == 'L') l++;
        if(r<=l+1){
            puts("NO");
            return 0;
        }
    }
    if(sc <= l || r <= sc){
        puts("NO");
        return 0;
    }
    l = 0, r = h + 1;
    for (int i = n-1; i >= 0; i--) {
        if(t[i] == 'U') r = min(r+1,h+1);
        else if(t[i] == 'D') l = max(0,l-1);
        if(s[i] == 'D') r--;
        else if(s[i] == 'U') l++;
        if(r<=l+1){
            puts("NO");
            return 0;
        }
    }
    if(sr <= l || r <= sr){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
