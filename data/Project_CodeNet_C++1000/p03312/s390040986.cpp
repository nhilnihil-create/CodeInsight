#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e17)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}

signed main(){
    int n;
    cin >> n;
    int A[n];
    REP(i,n) cin >> A[i];
    int ruisekiwa[n + 1];
    ruisekiwa[0] = 0;
    REP(i,n) ruisekiwa[i + 1] = ruisekiwa[i] + A[i];
    int zenhan[n],kouhan[n];

    int summ = A[0] + A[1];
    int tmp_sum = A[0];
    int id = 1;
    FOR(i,2,n){
        while( (tmp_sum + A[id]) * 2 <= ruisekiwa[i] ) tmp_sum += A[id], id ++;
        if( max(tmp_sum,ruisekiwa[i] - tmp_sum) <= max(tmp_sum + A[id] , ruisekiwa[i] - tmp_sum - A[id]) ) zenhan[i] = max(tmp_sum,ruisekiwa[i] - tmp_sum);
        else{
            tmp_sum += A[id];
            id ++;
            zenhan[i] = max(tmp_sum,ruisekiwa[i] - tmp_sum);
        }
    } 

    summ = A[n-1] + A[n-2];
    tmp_sum = A[n-1];
    id = n -2;
    REPR(i,n-2){
        while( (tmp_sum + A[id]) * 2 <= ruisekiwa[n] - ruisekiwa[i] ) tmp_sum += A[id], id--;
        if( max(tmp_sum,ruisekiwa[n] - ruisekiwa[i] - tmp_sum) <= max(tmp_sum + A[id],ruisekiwa[n] - ruisekiwa[i] - tmp_sum - A[id])) kouhan[i] = max(tmp_sum,ruisekiwa[n] - ruisekiwa[i] - tmp_sum);
        else{
            tmp_sum += A[id];
            id --;
            kouhan[i] = max(tmp_sum,ruisekiwa[n] - ruisekiwa[i] - tmp_sum);
        }
    }

    int ans = INF;
    FOR(i,2,n-1){
        chmin(ans, max(zenhan[i],kouhan[i]) - min(ruisekiwa[i] - zenhan[i],ruisekiwa[n] - ruisekiwa[i] - kouhan[i]) );
    }

    cout << ans << endl;
    
}