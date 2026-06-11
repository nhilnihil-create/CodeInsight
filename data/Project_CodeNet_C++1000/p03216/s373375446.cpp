#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = ;
const long long INF_LL = 1e18+3; const int INF_int = 1e9+3;
#define ll long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto itr = a.begin();itr!=a.end();itr++) cout << *itr << " ";cout << endl;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> m_acc(n+1);
    m_acc[0]=0LL;
    rep(i,n) m_acc[i+1]=m_acc[i]+int(s[i]=='M');
    vector<int> c_suf;
    rep(i,n) if(s[i]=='C') c_suf.push_back(i);
    ll csize = c_suf.size();
    vector<ll> m_in_c(csize);
    if(csize!=0){
        m_in_c[0] = m_acc[c_suf[0]];
        for(int i = 1;i<csize;i++) m_in_c[i]=m_acc[c_suf[i]]-m_acc[c_suf[i-1]];
    }
    vector<ll> m_in_c_acc(csize+1);
    m_in_c_acc[0]=0;
    rep(i,csize) m_in_c_acc[i+1]=m_in_c_acc[i]+m_in_c[i];

    lrep(i,csize) m_in_c[i]*=(csize-i);

    vector<ll> m_in_c_acc2(csize+1);
    m_in_c_acc[0]=0LL;
    rep(i,csize) m_in_c_acc2[i+1]=m_in_c_acc2[i]+m_in_c[i];

    vector<int> d_suf;
    rep(i,n) if(s[i]=='D') d_suf.push_back(i);

    int q;
    cin >> q;
    vector<ll> ansvec;
    /*Debug_Output_ALL(m_acc)
    Debug_Output_ALL(m_in_c)
    Debug_Output_ALL(m_in_c_acc)
    Debug_Output_ALL(m_in_c_acc2)
    Debug_Output_ALL(c_suf);*/
    rep(i,q){
        int dist;
        cin >> dist;
        ll ans = 0;
        rep(j,d_suf.size()){
            int nowd = d_suf[j];
            int f_suf = upper_bound(All(c_suf),nowd) - c_suf.begin();
            if(f_suf==csize) continue;
            vector<int>::iterator itr = lower_bound(All(c_suf),dist+nowd);
            if(itr==c_suf.begin()) continue;
            itr--;
            int l_suf = itr-c_suf.begin();
            if(l_suf<f_suf) continue;
            //if(i==1) cout << f_suf << " " << l_suf << " ";
            ans+=(m_in_c_acc2[l_suf+1]-m_in_c_acc2[f_suf+1]);
            ans-=((csize-l_suf-1)*(m_in_c_acc[l_suf+1]-m_in_c_acc[f_suf+1]));
            ans+=(l_suf-f_suf+1)*(m_acc[c_suf[f_suf]]-m_acc[nowd+1]);
            //if(i==1) cout << ans << endl;
        }
        ansvec.push_back(ans);
    }
    rep(i,ansvec.size()) cout << ansvec[i] << endl;
}