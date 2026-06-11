#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)

//template<typename T>
//using ordered_set =
//tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = (int)501;

int d , g;
pair< int , int > V[15];

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN ;
    cin >> d >> g;
    for(int i = 0; i < d; i++){
        cin >> V[i].first >> V[i].second;
    }
    int ans = 1 << 30;
    for(int mask = 0; mask < (1<<d) ; mask++){
        int score = 0 ;
        int q = 0;
        for(int i = 0; i < d ; i++){
            if( ( mask & (1<<i) )== 0 ) { continue ; }
            score+=( (i+1) * 100 * V[i].first ) + V[i].second ;
            q+=V[i].first;
        }
        if( score >= g){
            ans = min(ans,q); continue;
        }
        for(int i = d - 1; i >= 0; i--){
            if(mask&(1<<i)){ continue ; }
            int res = V[i].first;
            bool fl = 0;
            for(int j = 1; j < res; j++){
                int cur = ( 100 * (i+1)  * j );
                if( cur < (g-score) ){ continue; }
                score+=cur;
                q+=j;
                fl = 1;
                break;
            }
            if(fl){ break; }
        }
        if(score >= g){
            ans = min(ans,q);
        }
    }
    cout << ans << endl;
    return 0;
}
