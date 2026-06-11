//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mp make_pair
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef pair<int,int> P;

int n;
string s;
bool checker(){
    rip(i,n-1,0){
        if(s[i] != s[n-2-i]){
            return true;
        }
    }
    return (s[n-1] == '1' || s[0] == '0');
}

int main(){
    cin >> s;
    n = s.size();
    if(checker()){
        cout << -1 << endl;
        return 0;
    }
    vector<P> ans(0);
    int now = n/2;
    for(int i = n/2-1;i>-1;i--){
        ans.push_back(mp(i,now));
        if(s[i] == '1'){
            now = i;
        }
    }
    rip(i,n,n/2 + 1){
        ans.push_back(mp(n/2,i));
    }
    rip(i,n-1,0){
        printf("%d %d\n",ans[i].first + 1, ans[i].second + 1);
    }
}