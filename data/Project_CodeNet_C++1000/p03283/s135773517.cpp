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
vector< int > V[N + 5];

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int n , m , q;
    vector< int > L , R;
    cin >> n >> m >> q;
    while(m--){
        int l , r;
        cin >> l >> r;
        V[l].push_back(r);
    }
    for(int i = 0; i <= N; i++){
        sort(V[i].begin(),V[i].end());
    }
    while(q--){
        int l , r;
        cin >> l >> r;
        int sam = 0;
        for(int i = l; i <= r; i++){
            int res = upper_bound(V[i].begin(),V[i].end(),r) - V[i].begin();
            sam+=res;
        }
        cout << sam << endl;
    }
    return 0;
}
