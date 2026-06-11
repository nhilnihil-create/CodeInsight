//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll a_max=-INF;
    ll a_min=INF;
    int i_max,i_min;
    REP(i,N){
        cin >> a[i];
        if(a[i]>a_max){
            a_max=a[i];
            i_max=i;
        }
        if(a[i]<a_min){
            a_min=a[i];
            i_min=i;
        }
    }
    int m=0;
    vector<pair<int,int>> ans(100);
    if(a_min>=0){
        REP(i,N-1){
            if(a[i+1]<a[i]){
                ans[m]=make_pair(i+1,i+2);
                m++;
                a[i+1]+=a[i];
            }
        }
    }else if(a_max<=0){
        REPD2(i,N-1,0){
            if(a[i]<a[i-1]){
                ans[m]=make_pair(i+1,i);
                m++;
                a[i-1]+=a[i];
            }
        }
    }else{
        if(a_max>=-a_min){
            REP(i,N){
                if(a[i]<0){
                    ans[m]=make_pair(i_max+1,i+1);

                    m++;
                    a[i]+=a[i_max];
                }
            }
            REP(i,N-1){
                if(a[i+1]<a[i]){
                    ans[m]=make_pair(i+1,i+2);
                    m++;
                    a[i+1]+=a[i];
                }
            }
        }else{
            REP(i,N){
                if(a[i]>0){
                    ans[m]=make_pair(i_min+1,i+1);
                    m++;
                    a[i]+=a[i_min];
                }
            }
            REPD2(i,N-1,0){
                if(a[i]<a[i-1]){
                    ans[m]=make_pair(i+1,i);
                    m++;
                    a[i-1]+=a[i];
                }
            }
        }
    }

    cout << m <<endl;
    REP(i,m) cout << ans[i].first << " " << ans[i].second << endl;
    
}