#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, h;
    cin >> n >> h;
    vector<P> attack;
    rep(i, n){ 
        int a, b;
        cin >> a >> b;
        attack.emplace_back(a, 1);
        attack.emplace_back(b, 0);
    }
    sort(attack.begin(), attack.end(), greater<P>());

    int ans = 0;
    int sum = 0;
    for(auto at: attack){
        if (at.second == 0){
            sum += at.first; 
            ans++;
        } else {
            //この攻撃を繰り返す
            int num = ((h-sum)+at.first-1)/at.first;
            ans+=num;
            break;
        }
        if (sum >= h){
            break;
        }
    }
    
    cout << ans << endl;

}

