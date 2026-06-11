#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
 
using namespace std;
 
#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
 
#define MAX 200005
 
signed main(void) {
    int i,j;
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    bool b = true;
    rep(i,n-1)if(a[i] >= a[i+1])b = false;
    if(b){
        cout << 1 << endl;
        return 0;
    }
    int ok = MAX, ng = 1;
    while(ok-ng > 1){
 
        int mid = (ok+ng)/2;
        bool c = true;
        vector<pii> ans;
        ans.push_back(pii(a[0],0));
        rep(i,n-1){
            if(ans.empty()){
                c = false;
                break;
            }
            if(a[i] < a[i+1]){
                if(ans.back().second){
                    ans.push_back(pii(a[i+1]-a[i],0));
                }else{
                    ans.back().first += a[i+1]-a[i];
                }
            }else{
 
                int num = a[i] - a[i+1];//超過数
                while(num > 0 && ans.back().first <= num){
                    num -= ans.back().first;
                    ans.pop_back();
                }
                if(num)ans.back().first -= num;
                int t = ans.back().second;
                int add = 0;
                if(t+1 == mid){
                    //繰り上げ発生時
                    if(ans.size() == 1){
                        c = false;
                        break;
                    }
                    add += ans.back().first;
                    ans.pop_back();
                }
 
                //if(mid == 2)rep(j,ans.size())cout << " " << ans[j].first << " " << ans[j].second << endl;
                //一番最後の文字をインクリメントする
                if(ans.back().first == 1){
                    ans.back().second++;
                    t = ans.size()-1;
                    if(ans.size() >= 2 && ans[t].second == ans[t-1].second){
                        ans[t-1].first += ans[t].first;
                        ans.pop_back();
                    }
                }else{
                    t = ans.back().second;
                    ans.back().first--;
                    ans.push_back(pii(1,t+1));
                }
                if(add)ans.push_back(pii(add, 0));
            }
        }
 
        if(c)ok = mid;
        else ng = mid;
    }
 
    cout << ok << endl;
}