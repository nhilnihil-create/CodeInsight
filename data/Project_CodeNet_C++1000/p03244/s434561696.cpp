#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<int> even(100001),odd(100001);
    rep(i,n){
        if(i%2){
            odd[v[i]]++;
        }
        else{
            even[v[i]]++;
        }
    }
    int o1 = -1,ok1=-1;
    int o2 = -1,ok2=-1;
    int e1 = -1,ek1=-1;
    int e2 = -1,ek2=-1;
    for(int i=1; i<=100000; i++){
        if(o1 <= odd[i]){
            o2 = o1;
            ok2 = ok1;
            o1 = odd[i];
            ok1 = i;
        }else if(o2<=odd[i] && odd[i]<o1){
            o2 = odd[i];
            ok2 = i;
        }
        if(e1 <= even[i]){
            e2 = e1;
            ek2 = ek1;
            e1 = even[i];
            ek1 = i;
        }else if(e2<=even[i] && even[i]<e1){
            e2 = even[i];
            ek2 = i;
        }
    }
    if(ok1 != ek1){
        cout << n-o1-e1 << endl;
    }
    else if(ok1 == ek1){
        cout << min(n-o1-e2,n-o2-e1) << endl;
    }
    return 0;
}