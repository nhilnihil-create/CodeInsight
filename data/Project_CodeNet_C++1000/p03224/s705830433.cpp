#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<(e);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n == 1){
        cout << "Yes\n2\n1 1\n1 1" << endl;
    }else{
        LL x = 1;
        LL ct = 2;
        while(x < n){
           x+=ct;
           ct++;
        }
        if(x != n) cout << "No" << endl;
        else{
            ct--;
            cout << "Yes" << endl;
            cout << ct+1 << endl;
            vector<LL> st(ct+2, 1);
            st[0] = 0;
            int fi = 1;
            cout << ct << " ";
            REP(i, ct){
                cout << fi+i << " ";
            }
            cout << endl;
            
            st[fi] = ct;
            REP(i, ct){
                cout << ct << " ";
                LL now = fi;
                REP(j, ct){
                    cout << now+st[j] << " ";
                    now += st[j];
                }
                cout << endl;
                st[fi]--;
                st[fi+1] = st[fi];
                fi++;
            }
        }
    }

    return 0;
}
