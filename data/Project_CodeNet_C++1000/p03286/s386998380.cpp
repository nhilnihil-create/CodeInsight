#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <bitset>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
#define res(i, n) for(int (i)=0;(i)<(n);(i)++)
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 3001
#define INF (1 << 30)
#define MAXX 16002
#define MAXY 16002
#define MAXN 100010
#define MAXM 100001
#define MAXK 100001
#define MAXV 201
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;
struct edge {
    int to, cost;
};

int N;

string reverse(string s){
    string res = "";
    for(int i = s.length() - 1;i >= 0;i--){
        res += s[i];
    }
    return res;
}

string solve(int i){
    string res = "";
    while(i / -2){
        if(i > 0){
            res += (i % -2) + 48;
            i /= -2;
        }else{
            if(i % -2 < 0){
                res += (i % -2) + 50;
                i /= -2;
                i++;
            }else{
                res += 48;
                i /= -2;
            }
        }
    }
    if(i == 1){
        res += "1";
    }else if(i == -1){
        res += "11";
    }else{
        res += "0";
    }

    return reverse(res);
}

int main(){
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}