#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
//#define INF 1000000007
#define ARRAY_MAX 100005
const int INF = 1e9+7;

int main(){

    string s;
    cin >> s;
    int a = 0,b = 0,c = 0;

    for(int i = 0;i < s.length();i++){
        if(s[i] == 'a'){
            a++;
        }else if(s[i] == 'b'){
            b++;
        }else{
            c++;
        }
    }

    int mini = INF,maxi = -1;
    mini = min(min(a,b),c);
    maxi = max(max(a,b),c);
    if(maxi-mini <= 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



    return 0;
}
