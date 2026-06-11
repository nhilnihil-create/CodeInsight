#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back

using namespace std;


ll T;
ll A, B , C , D;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> T;
        while(T--) {

                cin >> A >> B >> C >> D;
                if(A < B) {
                        cout << "No\n"; continue;
                }else if(D < B) {
                        cout << "No\n"; continue;
                }
                if(C >= B-1){
                        cout << "Yes\n"; continue;
                }

                ll g = __gcd(B,D);
                A = A%B;
                ll yo = (B - A + g - 1) / g;
                yo--;
                if((A + yo*g)%B > C){
                        cout << "No\n";
                }else cout << "Yes\n";
        }
        return 0;
}
