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
int freq[ 105 ];
int lol[ 105 ];

void fact(int x){
    for(int i = 2; i <= 100 && x > 1; i++){
        if( x % i){ continue;}
        int cnt = 0;
        while( x % i == 0){
             ++cnt;
            x/=i;
        }
        freq[ i ]+=cnt;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN ;
    int n ;
    cin >> n;
    for(int i = 2; i <= n; i++){
        fact(i);
    }
    for(int i = 2; i <= n; i++){
        if(freq[i] >= 74){ lol[74]++;}
        if(freq[i] >= 24){ lol[24]++ ; }
        if(freq[i] >= 14){ lol[14]++ ; }
        if(freq[i] >= 4){ lol[4]++; }
        if(freq[i] >= 2){ lol[2]++ ; }
    }
    int res = 0;
    res+=lol[74];
    res+=(lol[24] * (lol[2]-1));
    res+=(lol[14] * (lol[4]-1));
    res+=( ( lol[4] * (lol[4]-1) / 2 ) * (lol[2]-2));
    cout << res << endl;
    return 0;
}
