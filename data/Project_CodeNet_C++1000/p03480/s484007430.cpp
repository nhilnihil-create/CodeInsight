#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iterator>
//#include<math.h>

using namespace std;
#define int long long
/*                      */    //#undef int
#define INF 1000000009
#define INFL 1000000000000000018ll
#define mod 1000000007ll
#define pb push_back
#define fi first
#define se second
#define mk(a, b) make_pair(a, b)
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef priority_queue<PA, vector<PA>, greater<PA> >PQG;

string s;
int n;

bool C(int x)
{
    if(x > n){
        return false;
    }
    int cnt = 0;
    string t = s;
    int rev[100005] = {0};
    for(int i = 0; i <= n - x; i++){
        if(i > 0){
            rev[i] += rev[i - 1];
        }
        if(t[i] == '0' && rev[i] % 2 == 1){
            rev[i]++;
            if(i + x < n){
                rev[i + x]--;
            }
        }
        else if(t[i] == '1' && rev[i] % 2 == 0){
            rev[i]++;
            if(i + x < n){
                rev[i + x]--;
            }
        }
    }
    for(int i = n - x + 1; i < n; i++){
        if(i > 0){
            rev[i] += rev[i - 1];
        }
        if((t[i] == '0' && rev[i] % 2 == 1) || (t[i] == '1' && rev[i] % 2 == 0)){
            if(i >= x){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int bs(int lb, int ub)
{
    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        if(C(mid)){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    return lb;
}

signed main()
{
    cin >> s;
    n = s.size();
    cout << bs(1, n + 1) << endl;


    return 0;
}
/*


*/
