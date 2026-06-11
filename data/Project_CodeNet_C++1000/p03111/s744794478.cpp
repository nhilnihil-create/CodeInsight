#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,A,B,C;
    cin >> N >> A >> B >> C;
    vector<int> L(N,0);
    rep(i,N) {
        cin >> L[i];
    }
    sort(L.begin(),L.end());
    int ans = INF;
    int tmp = 0;
    do {
        for (int i1=0; i1<N+1-3; i1++) {
            for (int i2=i1+1; i2<N+1-2; i2++) {
                for (int i3=i2+1; i3<N+1-1; i3++) {
                    for (int i4=i3+1; i4<N+1; i4++) {
                        int a,b,c;
                        a = b = c = 0;
                        tmp = 0;
                        for (int i=i1; i<i2; i++) {
                            a+=L[i];
                        }
                        for (int i=i2; i<i3; i++) {
                            b+=L[i];
                        }
                        for (int i=i3; i<i4; i++) {
                            c+=L[i];
                        }
                        tmp += abs(A-a);
                        tmp += abs(B-b);
                        tmp += abs(C-c);
                        tmp += 10*(i2-i1-1 + i3-i2-1+ i4-i3-1);
                        ans = min(ans,tmp);
                    }
                }
            }
        }
    } while(std::next_permutation(L.begin(),L.end()));
    cout << ans << endl;
}
