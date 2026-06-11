#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int D;
ll G;
vector<int> p;
vector<int> c;
vector<bool> sel;
int ans = 1000000;
void dfs(ll total, int num){
    if(sel.size()==D) {
        if(total>=G){
            ans = min(ans, num);
            return;
        }else{
            for (int i = D-1; i >= 0; i--)
            {
                if(!sel[i]){
                    if((G-total)/((i+1)*100)<p[i]){
                        num += max((G-total)/((i+1)*100), 1ll);
                        ans = min(num, ans);
                    }
                    break;
                }
            }
            return;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        sel.push_back(i);
        int it = sel.size();
        ll tmp = (i)? total+(it)*100*p[it-1]+c[it-1]:total;
        dfs(tmp, num+p[it-1]*i);
        sel.pop_back();
    }
    
}
int main() {
    cin >> D >> G;
  	p.resize(D);
  	c.resize(D);
    for (int i = 0; i < D; i++)
    {
        cin >> p[i] >> c[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}