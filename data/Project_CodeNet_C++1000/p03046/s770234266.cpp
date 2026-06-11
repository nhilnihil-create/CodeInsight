#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int m,k;
    cin>>m>>k;
    if(m==0||m==1){
        if(k){
            cout << -1<<endl;
        }else{
            if(m){
                cout << "0 0 1 1"<<endl;
            }else{
                cout <<"0 0"<<endl;
            }
        }
    }else{
        vector<int> v;
        int num=0;
        if(k>=(1<<m)){
            cout <<-1<<endl;
        }else{
            for(int i=0;i<(1<<m);i++){
                if(i!=k){
                    v.pb(i);
                    num^=i;
                }
            }
            if(num!=k){
                cout << -1<<endl;
            }else{
                int maki=v.size();
                for(int i=0;i<maki;i++){
                    cout << v[i] <<" ";
                }
                cout <<k<<" ";
                for(int i=maki-1;i>=0;i--){
                    cout << v[i]<<" ";
                }
                cout << k<<endl;
            }
        }
    }
    return 0;
}
