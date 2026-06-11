#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,k;cin>>n>>k;
    vector<pair<ll,ll>> sushi(n);
    ll t,d;
    rep(i,n){
        cin>>t>>d;
        sushi[i]=mp(d,t);
    }
    sort(all(sushi));
    reverse(all(sushi));
    //まずおいしさが大きい順にネタが被らないようにとっていく
    set<ll> used;//そのネタを使ったかフラグ
    priority_queue<pair<ll,ll>> pq;//使わなかったものを入れていく
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> ans;//各ネタのおいしさが最大のものを入れる.sizeは最大でもk
    set<pair<ll,ll>> tmp;//ansに入っているものを入れておく.用途後述
    ll sum=0;//ansに入っているもののおいしさ基礎ポイント
    rep(i,n){
        if(!used.count(sushi[i].second)){
            used.insert(sushi[i].second);
            ans.push(sushi[i]);
            sum+=sushi[i].first;
            tmp.insert(sushi[i]);
        }
        else pq.push(sushi[i]);
        if(ans.size()==k)break;//k種類目のネタのおいしさよりおいしさが小さいものをいれても満足ポイントは増えないのでここで打ち切る
    }
    ll kind=ans.size();
    while(ans.size()<k){//とりあえずansのsizeをkにして仮の答えを決めておく
        ans.push(pq.top());
        sum+=(pq.top()).first;
        pq.pop();
    }
    while(pq.size()){
        auto p=pq.top();pq.pop();
        auto q=ans.top();
        if(!tmp.count(q))break;//ansの中でおいしさが一番小さいやつのネタに関してそのネタの寿司が二種類以上あったら新しいものを加えても(ネタの種類は増えない)満足ポイントは増えない.
        //なぜならそのような場合新しく加えるやつのおいしさはansの中で最小のおいしさ以下だから.つまり, 簡単に言うとネタの種類の数が減らないなら加える意味はない.
        if(sum-q.first+(kind-1)*(kind-1)+p.first>sum+kind*kind){//加えて増加するならば加える
            ans.pop();
            ans.push(p);
            sum-=q.first;
            sum+=p.first;
            kind--;
            tmp.erase(q);
        }
        else break;//加えても増えないならそのおいしさ(p.first)より小さいおいしさの寿司については考える必要がないので打ち切る
    }
    cout<<sum+kind*kind<<endl;
}