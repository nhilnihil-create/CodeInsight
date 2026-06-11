#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

using namespace std;

int n;
int a[N];
set < pair < pair < int, int >, int > > s;

bool can(int m)
{
        s.clear();
        s.insert({{1, a[1]}, 1});
        for(int i = 2; i <= n; i++){
                if((--s.end())->fi.se < a[i]){
                        s.insert({{(--s.end())->fi.se + 1, a[i]}, 1});
                        continue;
                }
                while((--s.end())->fi.se > a[i]){
                        if((--s.end())->fi.fi > a[i]){
                                s.erase(--s.end());
                                continue;
                        }
                        auto p = *(--s.end());
                        s.erase(--s.end());
                        p.fi.se = a[i];
                        s.insert(p);
                }
                if((--s.end())->se < m){
                        auto p = *(--s.end());
                        s.erase(--s.end());
                        if(p.fi.fi != p.fi.se){
                                s.insert({{p.fi.fi, p.fi.se - 1}, p.se});
                        }
                        p.fi.fi = p.fi.se;
                        p.se += 1;
                        s.insert(p);
                        continue;
                }
                int L = (--s.end())->fi.fi;
                int R = (--s.end())->fi.se;
                s.erase(--s.end());
                while(!s.empty() && (--s.end())->se == m){
                        L = (--s.end())->fi.fi;
                        s.erase(--s.end());
                }
                if(s.empty()){
                        return false;
                }
                {
                        auto p = *(--s.end());
                        s.erase(--s.end());
                        if(p.fi.fi != p.fi.se){
                                s.insert({{p.fi.fi, p.fi.se - 1}, p.se});
                        }
                        p.fi.fi = p.fi.se;
                        p.se += 1;
                        s.insert(p);
                }
                s.insert({{L, R}, 1});
        }
        return true;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        int can1 = 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(i > 1 && a[i - 1] >= a[i]){
                        can1 = 0;
                }
        }
        if(can1){
                cout << 1 << "\n";
                return 0;
        }
        int l = 2, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
}
