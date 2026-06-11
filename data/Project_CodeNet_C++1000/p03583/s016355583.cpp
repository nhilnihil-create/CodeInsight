#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(x) x.begin(),x.end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

ll N;
ll solve(){
   ll ans=0;
   

   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int h=1;h<=3500;h++){
        for(int n=1;n<=3500;n++){
            ll numerator=h*n*N;
            ll denominator=4*h*n-n*N-h*N;
            if(denominator!=0&&numerator%denominator==0){
                ll res=numerator/denominator;
                if(res>0&&res<=3500){
                cout<<h<<" "<<n<<" "<<res;
                return 0;
                }
            }
        }
    }
    //cout<<solve()<<endl;
    return 0;
}