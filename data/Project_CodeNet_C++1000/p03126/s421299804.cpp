#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

void Suhaib_Sawalha (){

    int n , m;
    cin >> n >> m;
    int k , ans = 0 , p[m] = {};
    for (int i = 0 ; i < n ; ++i){
        cin >> k;
        int a;
        while (k--){
            cin >> a;
            p[a-1]++;
            ans += (p[a-1] == n);
        }
    }

    cout << ans;

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}