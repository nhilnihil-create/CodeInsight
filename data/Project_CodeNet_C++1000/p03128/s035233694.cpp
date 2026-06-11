//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


int main(){
    //IOS
    //freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    int val[10];
    val[0]=9999999;
    val[1]=2;
    val[2]=5;
    val[3]=5;
    val[4]=4;
    val[5]=5;
    val[6]=6;
    val[7]=3;
    val[8]=7;
    val[9]=6;
    vector<pair<int,int> >vec;
    for(int i=0;i<m;i++){

        int a;
        cin>>a;
        vec.pb({val[a],a});
    }
    string dp[n+10];
    for(int i=0;i<n+10;i++){
        dp[i]="-1";
    }

    dp[0]="";
    for(int i=0;i<n;i++){
        if(dp[i]=="-1")continue;
        for(int j=0;j<vec.size();j++){
            string cur=dp[i];
            char ch = (char)('0'+vec[j].second);
            //cout<<ch<<"\n";
            cur+=ch;
            //cout<<cur<<"\n";
            int v = i+vec[j].first;
            //cout<<v<<"\n";
            if(dp[v]=="-1"){
                dp[v]=cur;
            }
            else{
                if(dp[v].size()==cur.size()){
                    if(dp[v]<cur){
                        dp[v]=cur;
                    }
                }
                else if(dp[v].size()<cur.size()){
                    dp[v]=cur;
                }
            }

        }
    }
    cout<<dp[n]<<"\n";
}
