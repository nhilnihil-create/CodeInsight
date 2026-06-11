#include<bits/stdc++.h>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

typedef long long ll;

int N;
string S;
map<pair<string,string>,ll> mp1[20],mp2[20];

int main()
{
    scanf("%d",&N);
    cin >> S;

    mp1[0][mk("","")] = 1;
    for(int i = 0; i < N; i++)
    {
        for(auto ite = mp1[i].begin(); ite != mp1[i].end(); ite++)
        {
            string S1 = (ite->fi).fi,S2 = (ite->fi).se;
            ll tmp = ite->se;
            mp1[i + 1][mk(S1 + S[i],S2)] += tmp;
            mp1[i + 1][mk(S1,S2 + S[i])] += tmp;
        }
    }
    reverse(S.begin(),S.end());
    mp2[0][mk("","")] = 1;
    for(int i = 0; i < N; i++)
    {
        for(auto ite = mp2[i].begin(); ite != mp2[i].end(); ite++)
        {
            string S1 = (ite->fi).fi,S2 = (ite->fi).se;
            ll tmp = ite->se;
            mp2[i + 1][mk(S1 + S[i],S2)] += tmp;
            mp2[i + 1][mk(S1,S2 + S[i])] += tmp;
        }
    }

    ll ans = 0;
    for(auto ite = mp1[N].begin(); ite != mp1[N].end(); ite++)
    {
        ans += (mp2[N][ite->fi]) * (ite->se);
    }

    printf("%lld\n",ans);
    return 0;
}
