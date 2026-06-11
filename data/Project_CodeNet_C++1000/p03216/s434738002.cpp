#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,q,l,now,d,m,a,ans;
    string s;
    cin >> n;
    cin >> s;
    cin >> q;
    vector<int> k(q, 0);
    for (int i = 0;i<q;i++){
        cin >> k[i];
    }
    for (int qq = 0; qq < q;qq++){
        l=0;
        now=0;
        d=0;
        m=0;
        a=0;
        ans=0;
        vector<int> d_l, m_l;
        for (int i = 0; i < n;i++){
            char j = s[i];
            if (j == 'D')
            {
                d += 1;
                l += 1;
                d_l.push_back(i);
                m_l.push_back(0);
            }
            else if(j=='C'){
                ans += a;
            }
            if(l>now){
                if(j=='M'){
                    m += 1;
                    a+=d;
                    m_l[l - 1] += 1;
                }
                if(d_l[now]==i-k[qq]+1){
                    d -= 1;
                    a -= m;
                    m -= m_l[now];
                    now += 1;
                }
            }
        }
        cout << ans << endl;
    }
}